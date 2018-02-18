/* codgen.c       Generate Assembly Code for x86         15 May 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and The University of Texas at Austin
    */

/* Starter file for CS 375 Code Generation assignment.           */
/* Written by Gordon S. Novak Jr.                  */

/* This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License (file gpl.text) for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "symtab.h"
#include "genasm.h"
#include "codegen.h"
#include <limits.h>
#include <float.h>



/* Set DEBUGGEN to 1 for debug printouts of code generation */
#define DEBUGGEN  0

#define INTREG    8
#define FLOREG    24
#define NUMREG    32

double floreg = -DBL_MAX;
int floregnum = -1;


int reg_occ[32] = {
                0, 0, 0, 0, 0, 0, 0, 0,   //int - r7d
                0, 0, 0, 0, 0, 0, 0, 0,   //float - r15d
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
              };

int nextlabel;    /* Next available label number */
int stkframesize;   /* total stack frame size */

TOKEN funcall = NULL;
int num_funcalls;
int num_processed;
int saved_reg;
int saved_regs[10];

TOKEN saved_regr = NULL;
int saved_regr_num = -1; 

int saved_label = -1;

TOKEN prv_ptr = NULL; 
int prv_ptr_reg;
int prv_ptr_offset;

int prv_reg_id;

int nested_ref = 0;
TOKEN op_one_genarith = NULL;
TOKEN ref_stop_at = NULL; 

int new_fun = 0;

int null_flag = 0;

/* Top-level entry for code generator.
   pcode    = pointer to code:  (program foo (output) (progn ...))
   varsize  = size of local storage in bytes
   maxlabel = maximum label number used so far

Add this line to the end of your main program:
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
The generated code is printed out; use a text editor to extract it for
your .s file.
         */

void gencode(TOKEN pcode, int varsize, int maxlabel){  
  TOKEN name, code;
  name = pcode->operands;
  code = name->link->link;
  nextlabel = maxlabel + 1;
  stkframesize = asmentry(name->stringval,varsize);
  genc(code);
  asmexit(name->stringval);
}

/* Trivial version: always returns RBASE + 0 */
/* Get a register.   */
/* Need a type parameter or two versions for INTEGER or REAL */
int getreg(int kind) {
  if (DEBUGGEN) { 
    printf("getreg\n");
    printf("%i\n", kind);
  }

  int i = 0;
  int end = INTREG;
  if (kind !=  INTEGER && kind != POINTER) {
    i = 16;
    end = NUMREG;
  }

  for (; i < end; i++) {
    if (reg_occ[i] == 0) {
      reg_occ[i] = 1;
      return i;
    }
  }
  return RBASE;
}

int genarith(TOKEN code) {   
  int num, reg, regl, regr;
  SYMBOL tmp;

  if (DEBUGGEN) { 
    printf("genarith\n");
    dbugprinttok(code);
  }
  
  if (code->tokentype == NUMBERTOK) { 
    if (code->datatype == INTEGER) { 
      num = code->intval;
      reg = getreg(INTEGER);

      if (num >= MINIMMEDIATE && num <= MAXIMMEDIATE && !nested_ref)
        if (prv_ptr && prv_ptr_reg > -1) {
          asmimmed(MOVQ, num, reg);
          prv_ptr_reg = -1;
        }
        else if (!null_flag) 
          asmimmed(MOVL, num, reg);
        
        else 
          asmimmed(MOVQ, num, reg);
        
    }
    if (code->datatype == REAL) { 
      reg = getreg(REAL);
      floreg = code->realval;
      floregnum = reg;

      makeflit(code->realval, nextlabel);
      asmldflit(MOVSD, nextlabel++, reg);

    }
  }
  
  else if(code->tokentype == IDENTIFIERTOK) {
    tmp = searchst(code->stringval);
    if (!tmp) {
      return is_symbol_null(code->stringval);
    }

    num = tmp->offset;

    if (tmp->kind == FUNCTIONSYM) {
      reg = getreg(tmp->datatype->basicdt);
      funcall = code;
      genc(code->link);
    }

    else {
      reg = getreg(code->datatype);
      if (reg < NUMREG && code->datatype != POINTER) {

          SYMBOL temp = searchst(code->stringval);
          if (!temp) 
            return is_symbol_null(code->stringval);
          

          SYMBOL next = temp->datatype;

          if (!next) 
            return is_symbol_null(NULL);
          

          if (next->kind != ARRAYSYM){
            prv_reg_id = reg;
            asmld(MOVL, tmp->offset - stkframesize, reg, code->stringval);
          }
          
      }
      else {
        if (code->datatype == POINTER) {
          if (prv_ptr == NULL) {
            prv_ptr = code;
            prv_ptr_reg = reg;
            asmld(MOVQ, tmp->offset - stkframesize, reg, code->stringval);
          }

          else if (prv_ptr != NULL && strcmp(prv_ptr->stringval, code->stringval) != 0) {
            prv_ptr = code;
            prv_reg_id = reg;
            asmld(MOVQ, tmp->offset - stkframesize, reg, code->stringval);
          }
        }

        else {
          prv_reg_id = reg;
          asmld(MOVSD, tmp->offset - stkframesize, reg, code->stringval);
        }
      }       
    }
  }

  else if(code->tokentype == OPERATOR) {
    if (op_one_genarith == NULL) {
      op_one_genarith = code;
    }
    else {
      nested_ref = 1;
    }

    regl = genarith(code->operands);

    if (code->operands->link) {
        regr = genarith(code->operands->link);
    }
    else {
        regr = 0;
    }

    if (code->operands->whichval == FUNCALLOP) {

        free_reg(regl);
        regl = saved_regs[num_processed - 1];
        mark_reg_used(regl);
    }
    if (code->operands->link) {
      if (code->operands->link->whichval == FUNCALLOP) {
        free_reg(regr);
        regr = saved_regs[num_processed - 2];
        mark_reg_used(regr);
      }
    }

    int same_reg_assn = 0;
    if (regl == regr) {
      same_reg_assn = 1;
      if (regr > 15) {
          regl = getreg(REAL);
      }
      else {
          regl = getreg(INTEGER);
      }
    }

    regl = genop(code, regr, regl);
    free_reg(regr);
    if (same_reg_assn) {
      int temp;
      if (regl > 15) {
        free_reg(regl);
        temp = getreg(REAL);
      }
      else {
        free_reg(regl);
        temp = getreg(INTEGER);
      }
      regl = temp;
    }

    reg = regl;
  }
  else { 
    return is_symbol_null(NULL);
  }

  return reg;
}

/* Generate code for a Statement from an intermediate-code form */
void genc(TOKEN code) {  
  
  if (DEBUGGEN) { 
    printf("genc\n");
    dbugprinttok(code);
  }

  TOKEN tok, lhs, rhs;
  int num, reg, offs;
  SYMBOL sym;

  if (code->tokentype != OPERATOR) { 
    printf("Bad code token");
    dbugprinttok(code);

    if (code->tokentype == NUMBERTOK && code->datatype == INTEGER && new_fun) {
      reset_reg();
      new_fun = 0;
      return;
    }
  }
  reset_reg();

  switch (code->whichval){ 
    case PROGNOP:
      prv_ptr = NULL;
      prv_ptr_reg = -1;
      prv_ptr_offset = -1;

      ref_stop_at = NULL;

      int i = 0;
      for (; i < 10; i++) {
        saved_regs[i] = -1;
      }
      num_processed = 0;

      prv_reg_id = -1;

      tok = code->operands;
      while (tok) {
        num_funcalls = num_funcalls_tree(tok->operands, 0);
        saved_reg = 0;      

        if (tok->whichval == LABELOP) {
          saved_label = tok->operands->intval;
        }

        if (search_tree(tok, "new")) {
          new_fun = 1;
        }
        genc(tok);
        tok = tok->link;
      }
    break;
    case ASSIGNOP:
      if(0)
        printf("bla");
      TOKEN last = get_last_operand(code);
      TOKEN out_link = code->operands->link;  

      if (last)
        if (last->datatype == POINTER && out_link->tokentype == NUMBERTOK && out_link->datatype == INTEGER && out_link->intval == 0)
          null_flag = 1;
  

      lhs = code->operands;
      rhs = lhs->link;

      if (code->operands->operands != NULL)
        ref_stop_at = code->operands->operands;
      

      reg = genarith(rhs);            
      saved_regr = rhs;
      saved_regr_num = reg;
      sym = searchst(lhs->stringval);

      int datatype = code->datatype;                

      if (sym) {
        offs = sym->offset - stkframesize;    

        if (reg >= 0 && reg < 16) {
          if (lhs->datatype == 4) 
            asmst(MOVQ, reg, offs, lhs->stringval);   
          else 
            asmst(MOVL, reg, offs, lhs->stringval);
              
        }
        else 
          asmst(MOVSD, reg, offs, lhs->stringval);
        
      }

      else {
        sym = searchst(lhs->operands->stringval);
        if (!sym) {
          sym = searchst(lhs->operands->operands->stringval);
          if (sym) {
            offs = sym->offset - stkframesize;
            int temp = getreg(INTEGER);
            prv_ptr = lhs->operands->operands;

            asmld(MOVQ, offs, temp, sym->namestring);
            offs = lhs->operands->link->intval;

            if (basicsizes[rhs->datatype] > basicsizes[INTEGER]) {
                    
              if (floreg != -DBL_MAX) {
                asmstr(MOVSD, reg, offs, temp, "^. ");
              }
              else {
                 asmstr(MOVQ, reg, offs, temp, "^. ");
              }
            }
            else {
              if (!null_flag) { 
                asmstr(MOVL, reg, offs, temp, "^. ");
              }
              else {
                asmstr(MOVQ, reg, offs, temp, "^. ");
              }
            }
          } 
          else { }
        }
        else {

          offs = sym->offset - stkframesize;
          TOKEN last_link = get_last_link(lhs->operands);

          if (last_link) {
            if (last_link->tokentype == NUMBERTOK && last_link->datatype == INTEGER) {
              asmimmed(MOVL, last_link->intval, EAX);
              asmop(CLTQ);

              if (reg >= 0 && reg < 16) 
                asmstrr(MOVL, reg, offs, EAX, sym->namestring);
              
              else 
                asmstrr(MOVSD, reg, offs, EAX, sym->namestring);
              
            }
            else if (last_link->tokentype == OPERATOR && last_link->whichval == PLUSOP) {
              TOKEN plus_operand = last_link->operands;
              TOKEN mul_operand = plus_operand->link->operands;
              TOKEN last_operand = mul_operand->link;

              mark_reg_unused(EAX);
              mark_reg_used(prv_ptr_reg);

              int move_plus_to = getreg(INTEGER);
              int move_mul_to = getreg(INTEGER);
              int move_last_to;

              asmimmed(MOVL, plus_operand->intval, move_plus_to);
              asmimmed(MOVL, mul_operand->intval, move_mul_to);

              if (last_operand->tokentype == NUMBERTOK) {
                move_last_to = getreg(INTEGER);
                asmimmed(MOVL, last_operand->intval, move_last_to);
              }
              else {
                sym = searchst(last_operand->stringval);
                offs = sym->offset - stkframesize;          
                asmld(MOVL, offs, EBX, sym->namestring);    
                asmrr(IMULL, EBX, move_mul_to);
                asmrr(ADDL, move_mul_to, move_plus_to);
                asmop(CLTQ);

                sym = searchst(lhs->operands->stringval);
                offs = sym->offset - stkframesize;         
                asmstrr(MOVL, prv_ptr_reg, offs, 0, lhs->operands->stringval);
              }
            }
            else { }
          }
          else {
            if (reg >= 0 && reg < 16) 
                asmstrr(MOVL, reg, offs, getreg(INTEGER), sym->namestring);
            
            else 
                asmstrr(MOVSD, reg, offs, getreg(INTEGER), sym->namestring);
            
          }
        }
      }
      if (lhs->operands) {
        reg = genarith(lhs->operands);
      }

      null_flag = 0;
      floreg = -DBL_MAX;
      saved_regr = NULL;
      saved_regr_num = -1;
      nested_ref = 0;    

      prv_ptr = NULL;
      prv_ptr_reg = -1;

      ref_stop_at = NULL;
    break;
    case GOTOOP:
      lhs = code->operands;
      asmjump(JMP, lhs->intval);
    break;
    case LABELOP:
      lhs = code->operands;
      asmlabel(lhs->intval);
    break;
    case IFOP:
      lhs = code->operands;
      rhs = code->operands->link;
      int if_label_num = genarith(lhs);
      if (rhs->whichval == PROGNOP) 
        if (rhs->link != NULL) 
          asmjump(JMP, saved_label);
    
      asmjump(JMP, nextlabel);
      int else_label_num = nextlabel++;
      asmlabel(if_label_num);
      genc(rhs);
      asmlabel(else_label_num);
      genc(lhs);
    break;
    default:

      lhs = code->operands;
      rhs = code->operands->link;
      SYMBOL argsym;

      if (strstr(lhs->stringval, "write")) {     
        sym = searchst(lhs->stringval);

        if (rhs->tokentype == STRINGTOK) {
          asmlitarg(nextlabel, EDI);
          asmcall(lhs->stringval);
          makeblit(rhs->stringval, nextlabel++);
        }

        else if (rhs->tokentype == OPERATOR) {
          if (rhs->whichval == AREFOP) {
            sym = searchst(rhs->operands->stringval);
            if (!sym) {
              sym = searchst(rhs->operands->operands->stringval);
              if (sym) {
                reg = getreg(INTEGER);
                offs = sym->offset - stkframesize;
                asmld(MOVQ, offs, reg, sym->namestring);

                offs = rhs->operands->link->intval;
                int temp = getreg(REAL);
                asmldr(MOVSD, offs, reg, temp, "^.");

                asmcall(lhs->stringval);

              }
            }
          }
        }

        else if (sym != NULL && (sym->datatype->basicdt == INTEGER || sym->datatype->basicdt == REAL)) {
            
            SYMBOL argsym;

            if (rhs->tokentype == NUMBERTOK) {/*still doesn't work */}             

            else if (rhs->tokentype == IDENTIFIERTOK) {
              argsym = searchst(rhs->stringval);
              if (!argsym) {
                  printf("Error: no symbol table entry for var \"%s\"", rhs->stringval);
                  return;
              }

              if (argsym->basicdt == INTEGER) {
                  reg = getreg(INTEGER);
                  offs = argsym->offset - stkframesize;

                  asmld(MOVL, offs, reg, argsym->namestring);
                  asmrr(MOVL, reg, EDI);
                  asmcall(lhs->stringval);
              }

              else if (argsym->basicdt == REAL) {
                  reg = getreg(REAL);
                  offs = argsym->offset - stkframesize;
                  asmld(MOVSD, offs, reg, argsym->namestring);
                  asmrr(MOVSD, reg, EDI);
                  asmcall(lhs->stringval);
              }
            }
        }
      }

      else if (strcmp(lhs->stringval, "new") == 0) {
        new_fun = 1;
        num = lhs->intval;
        reg = getreg(INTEGER); 
        sym = lhs->symentry;
        offs = sym->offset - stkframesize;

        if (num >= MINIMMEDIATE && num <= MAXIMMEDIATE) {
          asmimmed(MOVL, num, reg);
        }

        asmrr(MOVL, reg, EDI);      
      }
    break;
  }
}



//my funs

int is_symbol_null(char *str) {
  if (str) 
    printf("symbol is null (\"%s\")\n", str);
  
  return 0;
}

int token_equal(TOKEN a, TOKEN b) {
    if (!a || !b) 
      return 0;
    

    if ((long) a == (long) b) 
      return 1;
    
    return 0;
}
int search_tree(TOKEN tok, char str[]) {
  if (tok == NULL) 
    return 0;
  

  int f = 0;

  if (strcmp(tok->stringval, str) == 0) 
    return 1;
  
  if (tok->link != NULL) 
    f = search_tree(tok->link, str);
  
  if (tok->operands != NULL) 
    f = search_tree(tok->operands, str);
  
  return f;
}
int genop(TOKEN code, int regr, int regl) {

  int tmp = 0;
  int which_val = code->whichval;

  if (which_val == PLUSOP) {
    if (is_float(regl, regr)) 
      asmrr(ADDSD, regr, regl);
    
    else 
      asmrr(ADDL, regr, regl);
    tmp = regl;
  }
  else if (which_val == MINUSOP) {
    if (regl > 15 && regl < NUMREG) {
        asmfneg(regl, getreg(REAL));
        regr = regl;
    }
    else if (is_float(regl, regr)) 
      asmrr(SUBSD, regr, regl);
    
    else 
      asmrr(SUBL, regr, regl);
    
    tmp = regl;
  }
  else if (which_val == TIMESOP) {
    if (is_float(regl, regr)) 
      asmrr(MULSD, regr, regl);
    
    else 
      asmrr(IMULL, regr, regl);

    tmp = regl;
  }
  else if (which_val == DIVIDEOP) {
    if (is_float(regl, regr)) 
        asmrr(DIVSD, regr, regl);
    else 
        asmrr(DIVL, regr, regl);
    tmp = regl;
  }
  else if (which_val == EQOP) {
    tmp = nextlabel++;
    asmrr(CMPL, regr, regl);
    asmjump(JE, tmp);
  }
  else if (which_val == NEOP) {
    tmp = nextlabel++;
    asmrr(CMPQ, regr, regl);
    asmjump(JNE, tmp);
  }
  else if (which_val == LTOP) {
    tmp = nextlabel++;
    asmrr(CMPL, regr, regl);
    asmjump(JL, tmp);
  }
  else if (which_val == LEOP) {
    tmp = nextlabel++;
    asmrr(CMPL, regr, regl);
    asmjump(JLE, tmp);
  }
  else if (which_val == GEOP) {
    tmp = nextlabel++;
    asmrr(CMPL, regr, regl);
    asmjump(JGE, tmp);
  }
  else if (which_val == GTOP) {
    tmp = nextlabel++;
    asmrr(CMPL, regr, regl);
    asmjump(JG, tmp);
  }
  else if (which_val == POINTEROP) {
    prv_ptr_offset = code->link->intval;

    if (ref_stop_at && nested_ref && token_equal(ref_stop_at, code)) 
        asmstr(MOVSD, saved_regr_num, code->link->intval, regl, "^. ");
    
    if (!nested_ref) 
        saved_regr = code->operands;
    else 
        saved_regr = code->link;
    
    tmp = regl;
  }
  else if (which_val == FUNCALLOP) {

      if (funcall) {
        if (num_funcalls > 1) {
          saved_regs[num_processed] = saved_reg;
          num_processed++;
          if (num_processed == 1) {
            asmcall(funcall->stringval);
            asmsttemp(saved_reg);
          }
          else if (num_processed > 0 && num_processed < num_funcalls) {}
          else {
            asmcall(funcall->stringval);
            asmldtemp(saved_reg);
          }               
        }
        else if (strcmp(funcall->stringval, "new") == 0) {
          asmrr(MOVL, regr, EDI);
          asmcall(funcall->stringval);
        }
        else {
          asmcall(funcall->stringval);
        }
        funcall = NULL;
      }
      else {}

      tmp = regl;
  }
  else if (which_val == AREFOP) {

    if (floreg != -DBL_MAX) 
      asmldr(MOVQ, code->operands->link->intval, regl, regr, "^.");
    
    else {
      if (prv_reg_id > -1) {
        int foo = regr;
        if (prv_reg_id > -1 && prv_reg_id < 16) {
          if (prv_reg_id == regr) {
            regr = getreg(INTEGER);
            free_reg(foo);
          }

          if (prv_ptr && prv_ptr_reg > -1) {
            int found = 0;
            SYMBOL tmp0, tmp1, tmp2, tmp3, typsym;
            tmp0 = searchst(prv_ptr->stringval);
            typsym = NULL;

            if (!tmp0) {
              return is_symbol_null(code->stringval);
            }

            tmp1 = searchst(tmp0->link->namestring);

            if (!tmp1) {
                return is_symbol_null(code->stringval);
            }

            if (tmp1->datatype->kind == ARRAYSYM) {
              typsym = tmp1->datatype;
              while (typsym && typsym->kind == ARRAYSYM) {
                typsym = typsym->datatype;
              }
              if (!typsym) {
                return is_symbol_null(code->stringval);
              }

              tmp2 = typsym->datatype;
              if (tmp2 && tmp2->kind == RECORDSYM) {
                tmp3 = tmp2->datatype;

                while (tmp3 && !found) {
                  if (tmp3->offset == prv_ptr_offset) {
                    found = 1;

                    if (tmp3->size > basicsizes[INTEGER]) {
                      asmldr(MOVQ, code->operands->link->intval, regl, regr, "^.");
                    }
                    else {
                      asmldr(MOVL, code->operands->link->intval, regl, regr, "^.");
                    }
                  }
                  tmp3 = tmp3->link;
                }
              }
            }
            else {}

            if (!found) {
              asmldr(MOVL, code->operands->link->intval, regl, regr, "^.");
            }

            prv_ptr_reg = -1;
          } 
          else {
            asmldr(MOVL, code->operands->link->intval, regl, regr, "^.");                        
          }

        }
        else {
          if (prv_reg_id == regr) {
            regr = getreg(REAL);
            free_reg(foo);
          }
          asmldr(MOVSD, code->operands->link->intval, regl, regr, "^.");
        }
      }
      else {
          free_reg(regr);
          regr = getreg(REAL);
          asmldr(MOVSD, code->operands->link->intval, regl, regr, "^.");
      }
    }
    prv_ptr_reg = regr;
    tmp = regr;
  }
  else if (which_val == FLOATOP) {
      int freg = getreg(REAL);
      asmfloat(regr, freg);
      free_reg(regl);
      free_reg(regr);
      tmp = freg;
  }
  else if (which_val == FIXOP) {
      int dreg = getreg(INTEGER);
      asmfix(regl, dreg);
      free_reg(regl);
      free_reg(regr);
      tmp = dreg;
  }

  if (funcall != NULL && num_funcalls > 0) {
      saved_reg = regr;
  }

  return tmp;
}
void free_reg(int reg) {
  if (reg < 0 || reg >= NUMREG) {
    return; 
  }
  reg_occ[reg] = 0;
}
void reset_reg() {
  int i;
  for (i = 0; i < NUMREG; i++) {
    reg_occ[i] = 0;
  }
}
void mark_reg_used(int reg) {
  if (reg < 0 || reg >= NUMREG)
    return;
  reg_occ[reg] = 1;    
}
void mark_reg_unused(int reg) {
  if (reg < 0 || reg >= NUMREG)
      return;
  
  reg_occ[reg] = 0;
}
int is_float(int regl, int regr) {
    if ((regl >= INTREG && regl < NUMREG) || 
        (regr >= INTREG && regr < NUMREG)) {
        return 1;
    }
    return 0;
}
int num_funcalls_tree(TOKEN tok, int num) {
  if (tok == NULL) 
    return num;
  
  if (tok->whichval == FUNCALLOP) 
    num++;
  
  if (tok->link != NULL) 
    num = num_funcalls_tree(tok->link, num);
  
  if (tok->operands != NULL) 
    num = num_funcalls_tree(tok->operands, num);
  
  return num;
}