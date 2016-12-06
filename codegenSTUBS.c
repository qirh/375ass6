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

void genc(TOKEN code);
void reset_regs(void);
void free_reg(int reg_num);

/* Set DEBUGGEN to 1 for debug printouts of code generation */
#define DEBUGGEN 0

int nextlabel;    /* Next available label number */
int stkframesize;   /* total stack frame size */

                     /* integer regs */
int used_regs[32] = { 0, 0, 0, 0, 0, 0, 0, 0,
                     /* FP regs; r8d to r15d */
                      0, 0, 0, 0, 0, 0, 0, 0,
                     /* xmm0 to xmm15 */
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                    };

#define NUM_INT_REGS    8
#define NUM_FP_REGS     24
#define NUM_REGS        32

/* Top-level entry for code generator.
   pcode    = pointer to code:  (program foo (output) (progn ...))
   varsize  = size of local storage in bytes
   maxlabel = maximum label number used so far

Add this line to the end of your main program:
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
The generated code is printed out; use a text editor to extract it for
your .s file.
         */

void gencode(TOKEN pcode, int varsize, int maxlabel)
  {  TOKEN name, code;
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

    /*     ***** NAIVE IMPLEMENTATION *****   */

    int i = 0;
    int stop = NUM_INT_REGS;
    if (kind != 0) {
        i = 8;
        stop = NUM_REGS;
    }

    for (; i < stop; i++) {
        if (used_regs[i] == 0) {
            used_regs[i] = 1;
            return i;
        }
    }

    return RBASE;
}

/* Trivial version */
/* Generate code for arithmetic expression, return a register number */
int genarith(TOKEN code) {

    if (DEBUGGEN) {
        printf("In genarith()\n");
        dbugprinttok(code);
    }

    int num, reg_num, lhs_reg, rhs_reg;

    if (code->tokentype == NUMBERTOK) {
        if (code->datatype == INTEGER) {
            num = code->intval;
            reg_num = getreg(INTEGER);
            if (num >= MINIMMEDIATE && num <= MAXIMMEDIATE) {
                asmimmed(MOVL, num, reg_num);
            }
            else {

                /* Generate literal for the value of the constant, then
                   load the literal into a register. */

            }

        }
        else {
            /* Generate literal for the value of the constant, then
               load the literal into a register. */

            num = code->intval;
            reg_num = getreg(REAL);
        }
    }
    else if (code->tokentype == IDENTIFIERTOK) {

    }
    else if (code->tokentype == OPERATOR) {

        reg_num = lhs_reg;
    }

    return reg_num;
}

/* Generate code for a Statement from an intermediate-code form */
void genc(TOKEN code) {

    if (DEBUGGEN) {
        printf("In genc()\n");
        dbugprinttok(code);
    }
    if (code->tokentype != OPERATOR) {
        printf("Bad code token!\n");
        dbugprinttok(code);
    }

    SYMBOL sym;
    TOKEN tok, lhs, rhs;
    int reg, offs;

    switch (code->whichval) {
        case PROGNOP:
            tok = code->operands;
            while (tok) {
                genc(tok);
                tok = tok->link;
            }
            break;

        case ASSIGNOP:                   /* Trivial version: handles I := e */
            lhs = code->operands;
            rhs = code->operands->link;
            reg = genarith(rhs);              /* generate rhs into a register */
            sym = lhs->symentry;              /* assumes lhs is a simple var  */
            offs = sym->offset - stkframesize; /* net offset of the var   */

            switch (code->datatype) {            /* store value into lhs  */
                case INTEGER:
                    asmst(MOVL, reg, offs, lhs->stringval);
                    break;

                /* ... */
            };
            break;
    };

}

void reset_regs() {
    int i;
    for (i = 0; i < NUM_REGS; i++) {
        used_regs[i] = 0;
    }
}

void free_reg(int reg_num) {
    if (reg_num < 0 || reg_num >= NUM_REGS) {
        printf("Error: cannot free register number %d\n", reg_num);
        return;
    }
    used_regs[reg_num] = 0;
}



