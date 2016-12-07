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

void genc(TOKEN code);

/* Set DEBUGGEN to 1 for debug printouts of code generation */
#define DEBUGGEN   0

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

TOKEN prv_ptr = NULL; 
int prv_ptr_reg;
int prv_ptr_offset;

int prv_reg_id;

int nested_ref = 0;
TOKEN op_one_genarith = NULL;
TOKEN ref_stop_at = NULL; 

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
int getreg(int kind)
  {
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

/* Trivial version */
/* Generate code for arithmetic expression, return a register number */
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
      reg = getreg(WORD);
      if (num >= MINIMMEDIATE && num <= MAXIMMEDIATE)
        asmimmed(MOVL, num, reg);
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
          if (!temp) {
              return is_symbol_null(code->stringval);
          }

          SYMBOL next = temp->datatype;

          if (!next) {
              return is_symbol_null(NULL);
          }

          if (next->kind != ARRAYSYM) {
              prv_reg_id = reg;
              asmld(MOVL, tmp->offset - stkframesize, reg, code->stringval);
          }
      }
      else {
        if (code->datatype == POINTER) {
          if (prv_ptr == NULL) {
              prv_ptr = code;
              prv_reg_id = reg;
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
void genc(TOKEN code)
  {  TOKEN tok, lhs, rhs;
     int reg, offs;
     SYMBOL sym;
     if (DEBUGGEN)
       { printf("genc\n");
   dbugprinttok(code);
       };
     if ( code->tokentype != OPERATOR )
        { printf("Bad code token");
    dbugprinttok(code);
  };
     switch ( code->whichval )
       { case PROGNOP:
     tok = code->operands;
     while ( tok != NULL )
       {  genc(tok);
    tok = tok->link;
        };
     break;
   case ASSIGNOP:                   /* Trivial version: handles I := e */
     lhs = code->operands;
     rhs = lhs->link;
     reg = genarith(rhs);              /* generate rhs into a register */
     sym = lhs->symentry;              /* assumes lhs is a simple var  */
     offs = sym->offset - stkframesize; /* net offset of the var   */
           switch (code->datatype)            /* store value into lhs  */
             { case INTEGER:
                 asmst(MOVL, reg, offs, lhs->stringval);
                 break;
                 /* ...  */
             };
           break;
   };
}



//my funs

int is_symbol_null(char *str) {
    if (str) {
        printf("symbol is null (\"%s\")\n", str);
    }
    return 0;
}

int token_equal(TOKEN a, TOKEN b) {
    if (!a || !b) {
        return 0;
    }

    if ((long) a == (long) b) {
        return 1;
    }
    return 0;
}

int genop(TOKEN code, int regr, int regl) {

  int out = 0;
  int which_val = code->whichval;

  if (which_val == PLUSOP) {
      if (is_float(regl, regr)) {
          asmrr(ADDSD, regr, regl);
      }
      else {
          asmrr(ADDL, regr, regl);
      }
      out = regl;
  }
  else if (which_val == MINUSOP) {
      if (regl > 15 && regl < NUMREG) {
          asmfneg(regl, getreg(REAL));
          regr = regl;
      }
      else if (is_float(regl, regr)) {
          asmrr(SUBSD, regr, regl);
      }
      else {
          asmrr(SUBL, regr, regl);
      }
      out = regl;
  }
  else if (which_val == TIMESOP) {
      if (is_float(regl, regr)) {
          asmrr(MULSD, regr, regl);
      }
      else {
          asmrr(IMULL, regr, regl);
      }
      out = regl;
  }
  else if (which_val == DIVIDEOP) {
      if (is_float(regl, regr)) {
          asmrr(DIVSD, regr, regl);
      }
      else {
          asmrr(DIVL, regr, regl);
      }
      out = regl;
  }
  else if (which_val == EQOP) {
      out = nextlabel++;
      asmrr(CMPL, regr, regl);
      asmjump(JE, out);
  }
  else if (which_val == NEOP) {
      out = nextlabel++;
      asmrr(CMPQ, regr, regl);
      asmjump(JNE, out);
  }
  else if (which_val == LTOP) {
      out = nextlabel++;
      asmrr(CMPL, regr, regl);
      asmjump(JL, out);
  }
  else if (which_val == LEOP) {
      out = nextlabel++;
      asmrr(CMPL, regr, regl);
      asmjump(JLE, out);
  }
  else if (which_val == GEOP) {
      out = nextlabel++;
      asmrr(CMPL, regr, regl);
      asmjump(JGE, out);
  }
  else if (which_val == GTOP) {
      out = nextlabel++;
      asmrr(CMPL, regr, regl);
      asmjump(JG, out);
  }
  else if (which_val == POINTEROP) {
      prv_ptr_offset = code->link->intval;

      if (ref_stop_at && nested_ref && token_equal(ref_stop_at, code)) {
          asmstr(MOVSD, saved_regr_num, code->link->intval, regl, "^. ");
      }

      if (!nested_ref) {
          saved_regr = code->operands;
      }
      else {
          saved_regr = code->link;
      }

      out = regl;
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
              else if (num_processed > 0 && num_processed < num_funcalls) {
                  // do nothing
              }
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
      else {
          // ?????????????????????????????
      }

      out = regl;
  }
  else if (which_val == AREFOP) {

      if (floreg != -DBL_MAX) {
          asmldr(MOVQ, code->operands->link->intval, regl, regr, "^.");
      }
      else {
          if (prv_reg_id > -1) {
              int temp = regr;
              if (prv_reg_id > -1 && prv_reg_id < 16) {
                  if (prv_reg_id == regr) {
                      regr = getreg(INTEGER);
                      free_reg(temp);
                  }

                  if (prv_ptr && prv_ptr_reg > -1) {

                      int found = 0;
                      SYMBOL temp0, temp1, temp2, temp3, temp4, temp5, typsym;
                      temp0 = searchst(prv_ptr->stringval);
                      typsym = NULL;

                      if (!temp0) {
                          return is_symbol_null(code->stringval);
                      }

                      temp1 = searchst(temp0->link->namestring);

                      if (!temp1) {
                          return is_symbol_null(code->stringval);
                      }

                      if (temp1->datatype->kind == ARRAYSYM) {
                          typsym = temp1->datatype;
                          while (typsym && typsym->kind == ARRAYSYM) {
                              typsym = typsym->datatype;
                          }

                          if (!typsym) {
                              return is_symbol_null(code->stringval);
                          }

                          temp2 = typsym->datatype;
                          if (temp2 && temp2->kind == RECORDSYM) {
                              temp3 = temp2->datatype;

                              while (temp3 && !found) {
                                  if (temp3->offset == prv_ptr_offset) {
                                      found = 1;

                                      if (temp3->size > basicsizes[INTEGER]) {
                                          asmldr(MOVQ, code->operands->link->intval, regl, regr, "^.");
                                      }
                                      else {
                                          asmldr(MOVL, code->operands->link->intval, regl, regr, "^.");
                                      }
                                  }
                                  temp3 = temp3->link;
                              }
                          }

                      }
                      else {

                      }

                      // probably broken
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
                      free_reg(temp);
                  }
                  asmldr(MOVSD, code->operands->link->intval, regl, regr, "^.");
              }
              // else // WHAT ABOUT IF LHS IS > 15 ???????????????????????????????????????????????????
          }
          else {
              free_reg(regr);
              regr = getreg(REAL);
              asmldr(MOVSD, code->operands->link->intval, regl, regr, "^.");
          }

      }

      prv_ptr_reg = regr;
      
      out = regr;

  }
  else if (which_val == FLOATOP) {
      int freg = getreg(REAL);
      asmfloat(regr, freg);
      free_reg(regl);
      free_reg(regr);
      out = freg;
  }
  else if (which_val == FIXOP) {
      int dreg = getreg(INTEGER);
      asmfix(regl, dreg);
      free_reg(regl);
      free_reg(regr);
      out = dreg;
  }

  if (funcall != NULL && num_funcalls > 0) {
      saved_reg = regr;
  }

  return out;
}
void free_reg(int reg) {
  if (reg < 0 || reg >= NUMREG) {
    return; 
  }
  reg_occ[reg] = 0;
}
void mark_reg_used(int reg) {
    if (reg < 0 || reg >= NUMREG) {
        return;
    }
    reg_occ[reg] = 1;    
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