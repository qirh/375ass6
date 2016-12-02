%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include <string.h>


        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;


%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH

%error-verbose
%%

  program   : PROGRAM IDENTIFIER LPAREN id_list RPAREN SEMICOLON lblock DOT  
                                                        { printdebug( "1 program\n" ); parseresult = makeprogram($2, $4, $7); }
            ;
  variable  : IDENTIFIER                                { printdebug( "1 variable\n" ); $$ = findid($1); }
            | variable DOT IDENTIFIER                   { printdebug( "2 variable\n" ); $$ = reducedot($1, $2, $3); }
            | variable POINT                            { printdebug( "3 variable\n" ); $$ = dopoint($1, $2); }
            | variable LBRACKET expr_list RBRACKET      { printdebug( "4 variable\n" ); $$ = arrayref($1, $2, $3, $4);}
            ;
  id_list   : IDENTIFIER COMMA id_list                  { printdebug( "1 id_list\n" ); $$ = cons($1, $3); }
            | IDENTIFIER                                { printdebug( "2 id_list\n" ); $$ = cons($1, NULL); }
            ;  
  type      : simple_type                               { printdebug( "1 type\n" ); }
            | ARRAY LBRACKET simple_type_list RBRACKET OF type { printdebug( "2 type\n" ); $$ = instarray($3, $6); }
            | POINT IDENTIFIER                          { printdebug( "3 type\n" ); $$ = instpoint($1, $2);; }
            | RECORD field_list END                     { printdebug( "4 type\n" ); $$ = instrec($1, $2); }      
            ;  
  num_list  : NUMBER COMMA num_list                     { printdebug( "1 num_list\n" ); instlabel($1); }
            | NUMBER                                    { printdebug( "2 num_list\n" ); instlabel($1); }
            ; 
  fields    : id_list COLON type                        { printdebug( "1 fields\n" ); $$ = instfields($1, $3); }
            ;
  field_list: fields SEMICOLON field_list               { printdebug( "1 field_list\n" ); $$ = nconc($1, $3); }
            | fields                                    { printdebug( "2 field_list\n" ); }
            //| fields endpart SEMICOLON                  { printdebug( "3 field_list\n" ); }
            //| fields endpart                            { printdebug( "4 field_list\n" ); }
            //| fields SEMICOLON                          { printdebug( "5 field_list\n" ); }
            ;
  constant  : IDENTIFIER                                { printdebug( "1 constant\n" ); }
            | NUMBER                                    { printdebug( "2 constant\n" ); }
            | STRING                                    { printdebug( "3 constant\n" ); } 
            | sign NUMBER                               { printdebug( "4 constant\n" ); }
            | sign IDENTIFIER                           { printdebug( "5 constant\n" ); }
            ;
  simple_type: IDENTIFIER                               { printdebug( "1 simple_type\n" ); $$ = findtype($1); }
            | LPAREN id_list RPAREN                     { printdebug( "2 simple_type\n" ); $$ = instenum($2); }
            | NUMBER DOTDOT NUMBER                      { printdebug( "3 simple_type\n" ); $$ = makesubrange($2, $1->intval, $3->intval);; }
            ;
  simple_type_list : simple_type COMMA simple_type_list { printdebug( "1 simple_type_list\n" ); $$ = cons($3, $1); }
                   | simple_type                        { printdebug( "2 simple_type_list\n" ); }
                   ;
  block     : BEGINBEGIN statement endpart              { printdebug( "1 block\n" ); $$ = makeprogn($1, cons($2, $3));  }
            ;
  cdef      : IDENTIFIER EQ constant                    { printdebug( "1 cdef\n" ); instconst($1, $3); }
            ;
  cdef_list : cdef SEMICOLON cdef_list                  { printdebug( "1 cdef_list\n" ); cons($1, $3); }
            | cdef SEMICOLON                            { printdebug( "2 cdef_list\n" ); cons($1, NULL); }
            ;
  cblock    : CONST cdef_list tblock                    { printdebug( "1 cblock\n" ); $$ = $3; }
            | tblock                                    { printdebug( "2 cblock\n" ); }
            ;
  tdef      : IDENTIFIER EQ type                        { printdebug( "1 tdef\n" ); insttype($1, $3); }
            ;
  tdef_list : tdef SEMICOLON tdef_list                  { printdebug( "1 tdef_list\n" ); }
            | tdef                                      { printdebug( "2 tdef_list\n" ); }
            | tdef SEMICOLON                            { printdebug( "2 tdef_list\n" ); }
            ;
  tblock    : TYPE tdef_list vblock                     { printdebug( "1 tblock\n" ); $$ = $3; }
            | vblock                                    { printdebug( "2 tblock\n" ); }
            ;
  lblock    : LABEL num_list SEMICOLON cblock           { printdebug( "1 lblock\n" ); $$ = $4; }
            | cblock                                    { printdebug( "2 lblock\n" ); }
            ;
  vdef      : id_list COLON type                        { printdebug( "1 vdef\n" ); instvars($1, $3); }
            ;
  vdef_list : vdef SEMICOLON vdef_list                  { printdebug( "1 vdef_list\n" ); cons($1, $3); }
            | vdef                                      { printdebug( "2 vdef_list\n" ); }
            | vdef SEMICOLON                            { printdebug( "3 vdef_list\n" ); }
            ;
  vblock    : VAR vdef_list block                       { printdebug( "*******1 vblock\n" ); $$ = $3; }
            | block                                     { printdebug( "2 vblock\n" ); }
            ; 
  funcall   : IDENTIFIER LPAREN expr_list RPAREN        { printdebug( "1 funcall\n" ); $$ = makefuncall(talloc(), $1, $3); }
            ;
  statement : BEGINBEGIN statement endpart              { printdebug( "1 statement\n" ); $$ = makeprogn($1, cons($2, $3)); }
            | NUMBER COLON statement                    { printdebug( "2 statement\n" ); $$ = dolabel($1, $2, $3); }
            | assignment                                { printdebug( "3 statement\n" ); }
            | funcall                                   { printdebug( "4 statement\n" ); }
            | IF expression THEN statement endif        { printdebug( "5 statement\n" ); $$ = makeif($1, $2, $4, $5); }
            | FOR assignment TO expression DO statement { printdebug( "6 statement\n" ); $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
            | WHILE expression DO statement             { printdebug( "7 statement\n" ); $$ = makewhile($1,$2,$3,$4); }
            | REPEAT statement_list UNTIL expression    { printdebug( "8 statement\n" ); $$ = makerepeat($1, $2, $3, $4); }
            | IDENTIFIER LPAREN args RPAREN             { printdebug( "9 statement\n" ); $$ = makefuncall($2, $1, $3); }
            | GOTO NUMBER                               { printdebug( "A statement\n" ); }
            ;
  statement_list: statement SEMICOLON statement_list    { printdebug( "1 statement_list\n" ); $$ = cons($1, $3); }
            | statement                                 { printdebug( "2 statement_list\n" ); }
            ;
  endpart   : SEMICOLON statement endpart               { printdebug( "1 endpart\n" ); $$ = cons($2, $3); }
            | END                                       { printdebug( "2 endpart\n" ); $$ = NULL; }
            ;
  endif     : ELSE statement                            { printdebug( "1 endif\n" ); $$ = $2; }
            | /* empty */                               { printdebug( "2 endif\n" ); $$ = NULL; }
            ;
  assignment: variable ASSIGN expression                { printdebug( "1 assignment\n" ); $$ = binop($2, $1, $3); }
            ;
  expr_list : expression COMMA expr_list                { printdebug( "1 expr_list\n" ); $$ = cons($1, $3); }
            | expression                                { printdebug( "2 expr_list\n" ); }
            ;
  expression: expression compare_op simple_expression   { printdebug( "1 expression\n" ); $$ = binop($2, $1, $3); }
            | expression sign simple_expression         { printdebug( "2 expression\n" ); $$ = binop($2, $1, $3); }
            | simple_expression                         { printdebug( "3 expression\n" ); }
            ;
  simple_expression: simple_expression sign term        { printdebug( "1 simple_expression\n" ); $$ = binop($2, $1, $3); }
            | term                                      { printdebug( "2 simple_expression\n" ); }
            | sign term                                 { printdebug( "3 simple_expression\n" ); $$ = unaryop($1, $2); }
            | STRING                                    { printdebug( "4 simple_expression\n" ); }
            ;
  term      : term times_op factor                      { printdebug( "1 term\n" ); $$ = binop($2, $1, $3); }
            | factor                                    { printdebug( "2 term\n" ); }
            ;
  factor    : LPAREN expression RPAREN                  { printdebug( "1 factor\n" ); $$ = $2; }
            | MINUS variable                            { printdebug( "2 factor FUNCTION\n" ); $$ = unaryop($1, $2); }
            | MINUS NUMBER                              { printdebug( "3 factor FUNCTION\n" ); $$ = unaryop($1, $2); }
            | variable                                  { printdebug( "4 factor\n" ); }
            | constant                                  { printdebug( "5 factor\n" ); }    
            | funcall                                   { printdebug( "6 factor\n" ); }   
            | NIL                                       { printdebug( "7 factor\n" ); $$ = convertnil($1); }
            ;
  args      : expression COMMA args                     { printdebug( "1 args\n" ); $$ = cons($1, $3); }
            | expression                                { printdebug( "2 args\n" ); $$ = cons($1, NULL); }
            ;
  compare_op: EQ                                        { printdebug( "1 compare_op\n" ); }
            | LT                                        { printdebug( "2 compare_op\n" ); }
            | GT                                        { printdebug( "3 compare_op\n" ); }
            | NE                                        { printdebug( "4 compare_op\n" ); }
            | LE                                        { printdebug( "5 compare_op\n" ); }
            | GE                                        { printdebug( "6 compare_op\n" ); }
            | IN                                        { printdebug( "7 compare_op\n" ); }
            ;
  sign      : PLUS                                      { printdebug( "1 sign\n" ); }
            | MINUS                                     { printdebug( "2 sign\n" ); }
            ;
  times_op  : TIMES                                     { printdebug( "1 times_op\n" ); }
            | DIVIDE                                    { printdebug( "2 times_op\n" ); }
            ;
%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG 0
typedef enum {false, true} bool;
int labels[50];          //max labels
int labelnumber = 0;  /* sequential counter for internal label numbers */

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list) {
  
  printdebug( "cons()\n" );
  item->link = list;
  if( DEBUG ) {
    printdebug( "cons\n" );
    dbugprinttok(item);
    dbugprinttok(list);
  };
  printdebug( "cons() ends \n\n" );
  return item;

}

TOKEN unaryop(TOKEN op, TOKEN lhs) {
  
  printdebug( "unaryop()\n" );
  op->operands = lhs;
  lhs->link = NULL;
  
  printdebug( "unaryop() ends \n\n" );
  return op;

}
TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs) { 
  
  printdebug( "binop()\n" );
  op->operands = lhs;          /* link operands to operator       */
  lhs->link = rhs;             /* link second operand to first    */
  rhs->link = NULL;            /* terminate operand list          */
  if( DEBUG ){ 
    dbugprinttok(op);
    dbugprinttok(lhs);
    dbugprinttok(rhs);
  }
  printdebug( "binop() ends \n\n" );
  return op;

}
TOKEN findid(TOKEN tok){
  
  printdebug( "findid()\n" );
  SYMBOL sym, typ;
  sym = searchst(tok->stringval);

  if(sym->kind != CONSTSYM){ //from project 3
    tok->symentry = sym;
    typ = sym->datatype;
    tok->symtype = typ;

    if (typ->kind == BASICTYPE || typ->kind == POINTERSYM)
      tok->datatype = typ->basicdt;
  }
  else { //sym->kind == CONSTSYM
    tok->tokentype = NUMBERTOK;

    if(sym->basicdt ==0){           //INTEGER
      tok->datatype = INTEGER;
      tok->intval = sym->constval.intnum;
    }
    else if (sym->basicdt == 1) {     //REAL
      tok->datatype = REAL;
      tok->realval = sym->constval.realnum;
    }
  }
  if (DEBUG) { 
    dbugprinttok(tok);
  }

  printdebug( "findid() ends \n\n" );
  return tok;

}
void instvars(TOKEN id_list, TOKEN typetok) {
 
  printdebug( "instvars() \n" );

  SYMBOL sym, typesym;
  typesym = typetok->symtype;

  int align = 0;
  if (typesym->size > 4)
    align = 16;
  else
    align = alignsize(typesym);

  while (id_list != NULL) {
    sym = insertsym(id_list->stringval);
    sym->kind = VARSYM;
    sym->offset = wordaddress(blockoffs[blocknumber], align);
    sym->size = typesym->size;
    blockoffs[blocknumber] = sym->offset + sym->size;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    id_list = id_list->link;
  }
  printdebug( "instvars() ends \n\n" );

}
void instconst(TOKEN idtok, TOKEN consttok) {
  
  printdebug( "instconst()\n" );

  SYMBOL sym, typesym;
  
  sym = insertsym(idtok->stringval);
  sym->kind = CONSTSYM;

  sym->basicdt = consttok->datatype;

  //INTEGER
  if(sym->basicdt == 0){
    sym->size = 4;
    sym->constval.intnum = consttok-> intval;
  }
  //REAL
  else if (sym->basicdt == 1){  
    sym->size = 8;
    sym->constval.realnum = consttok-> realval;
  }

  if (DEBUG) { 
    dbugprinttok(idtok);
    dbugprinttok(consttok);
  }
  printdebug( "instconst() ends \n\n" );

}
TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart) {
  
  printdebug( "makeif()\n" );
  tok->tokentype = OPERATOR;
  tok->whichval = IFOP;
  if (elsepart != NULL) elsepart->link = NULL;
  thenpart->link = elsepart;
  exp->link = thenpart;
  tok->operands = exp;
  if (DEBUG) {
    dbugprinttok(tok);
    dbugprinttok(exp);
    dbugprinttok(thenpart);
    dbugprinttok(elsepart);
  };
  printdebug( "makeif() ends \n\n" );
  return tok;

}
TOKEN makeprogn(TOKEN tok, TOKEN statements) {
 
  printdebug( "makeprogn()\n" );
  tok->tokentype = OPERATOR;
  tok->whichval = PROGNOP;
  tok->operands = statements;
  if (DEBUG) {
    printdebug( "makeprogn\n" );
    dbugprinttok(tok);
    dbugprinttok(statements);
    ppexpr(tok);
  };
  printdebug( "makeprogn() ends \n\n" );
  return tok;

}
TOKEN makelabel() {
  
  printdebug( "makelabel()\n" );
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = LABELOP;
  tok->operands = makeintc(labelnumber);
  labelnumber += 1;
  
  printdebug( "makelabel() ends \n\n" );
  return tok;

}
TOKEN makegoto(int label) {
 
  printdebug( "makegoto()\n" );
  TOKEN gotoTok = talloc();
  gotoTok->tokentype = OPERATOR;
  gotoTok->whichval = GOTOOP;
  gotoTok->operands = makeintc(labelnumber - 1);
  
  printdebug( "makegoto() ends \n\n" );
  return gotoTok;

}
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
  
  printdebug( "makefuncall() with args\n" );
  if( DEBUG )
    ppexpr(args);

  tok->tokentype = OPERATOR;
  tok->whichval = FUNCALLOP;

  fn->link = args;
  tok->operands = fn;

  printdebug( "makefuncall() ends \n\n" );
  return tok;

}
TOKEN makeintc(int num) {
  
  printdebug( "makeintc()\n" );
  
  TOKEN tmp = talloc();
  tmp->tokentype = NUMBERTOK;
  tmp->datatype = INTEGER;
  tmp->intval = num;
  
  printdebug( "makeintc() ends \n\n" );
  return tmp;

}
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
 
  printdebug( "makeprogram()" );
  if( DEBUG ){
    printf(" with args:\n\t" );
    ppexpr(args);
  }
  else
    printdebug( "\n" );

  TOKEN program = talloc();
  TOKEN tmpArgs = talloc();
  program->tokentype = OPERATOR;
  program->whichval = PROGRAMOP;
  program->operands = name;
  
  tmpArgs->tokentype = OPERATOR;
  tmpArgs->whichval = PROGNOP;
  name->link = tmpArgs;

  tmpArgs->operands = args;
  tmpArgs->link = statements;
  
  printdebug( "makeprogram() ends \n\n" );
  return program;

}
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr, TOKEN tokc, TOKEN statement) {

  printdebug( "makefor() \n\t" );

  tok->tokentype = OPERATOR;
  tok->whichval = PROGNOP;
  tok->operands = asg;

  tokb->tokentype = OPERATOR;
  tokb->whichval = LABELOP;
  asg->link=tokb;
  
  TOKEN tok1 = talloc();
  tok1->tokentype = NUMBERTOK;
  tok1->datatype = INTEGER;
  labelnumber+=1;
  tok1->intval = labelnumber; 
  
  tokb->operands = tok1;
  tokc->tokentype = OPERATOR;
  tokc->whichval = IFOP;
  tokb->link = tokc;
  
  TOKEN tok2 = talloc();
  tok2->tokentype = OPERATOR;
  tok2->whichval = LEOP;
  tokc->operands = tok2;

  TOKEN tok3 = talloc();
  tok3->tokentype = asg->operands->tokentype;
  strcpy (tok3->stringval,asg->operands->stringval);
  tok3->link = endexpr;
  tok2->operands = tok3;
  
  TOKEN tok4 = talloc();
  tok4->tokentype = OPERATOR;
  tok4->whichval = PROGNOP;
  tok2->link = tok4;
  tok4->operands = statement;

  TOKEN tok5 = talloc();
  tok5->tokentype = OPERATOR;
  tok5->whichval = ASSIGNOP;
  statement->link = tok5;

  TOKEN tok6 = talloc();
  tok6->tokentype = asg->operands->tokentype;
  strcpy (tok6->stringval,asg->operands->stringval);
  tok5->operands = tok6;
  
  TOKEN tok7 = talloc();
  tok7->tokentype = OPERATOR;
  tok7->whichval = PLUSOP;
  tok6->link = tok7;

  TOKEN tok8 = talloc();
  tok8->tokentype = asg->operands->tokentype;
  strcpy (tok8->stringval,asg->operands->stringval);
  tok7->operands = tok8;

  TOKEN tok9 = talloc();
  tok9->tokentype = NUMBERTOK;
  tok9->datatype = INTEGER;
  tok9->intval = 1;
  tok8->link = tok9;

  TOKEN tokA = talloc();
  tokA->tokentype = OPERATOR;
  tokA->whichval = GOTOOP;
  tok5->link = tokA;

  TOKEN tokB = talloc();
  tokB->tokentype = NUMBERTOK;
  tokB->datatype = INTEGER;
  tokB->intval = labelnumber;
  tokA->operands = tokB;
  
  if (DEBUG){ 
    printdebug( "makefor\n" );
    dbugprinttok(tok);
    dbugprinttok(asg);
    dbugprinttok(tokb);
    dbugprinttok(endexpr);
    dbugprinttok(tokc);
    dbugprinttok(statement);
    ppexpr(tok);
  }
   
  printdebug( "makefor() ends \n\n" );
  return tok;

}
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokxzczxv, TOKEN expr) {
 
  printdebug( "makerepeat() \n" );

  TOKEN tok1 = talloc();
  tok1->tokentype = OPERATOR;
  tok1->whichval = PROGNOP;
  
  TOKEN tok2 = talloc();
  tok2->tokentype = OPERATOR;
  tok2->whichval = LABELOP;
  
  TOKEN tok3 = talloc();    //int
  tok3->tokentype = NUMBERTOK;
  tok3->datatype = INTEGER;
  int lbl = labelnumber++;
  tok3->intval = lbl;
  
  tok1->operands = tok2;
  tok2->operands = tok3;
  tok2->link= statements; 

  if( DEBUG ){
    printdebug( "tok1: \n\t" );
    ppexpr(tok1);
  }
  
  TOKEN tok4 = talloc();
  tok4->tokentype = OPERATOR;
  tok4->whichval = IFOP;
  statements->link = tok4;  
  tok4->operands = expr;
  
  TOKEN tok5 = talloc();
  tok5->tokentype = OPERATOR;
  tok5->whichval = PROGNOP;
  expr->link = tok5;
  

  TOKEN tok6 = talloc();
  tok6->tokentype = OPERATOR;
  tok6->whichval = GOTOOP;
  tok5->link = tok6;
  

  TOKEN tok7 = talloc();
  tok7->tokentype = NUMBERTOK;
  tok7->datatype = INTEGER;
  tok7->intval = lbl;
  tok6->operands = tok7;

  if(DEBUG){
    printdebug( "tok1: \n\t" );
    ppexpr(tok1);
  }
  printdebug( "makerepeat() ends \n\n" );
  return tok1;

}
TOKEN findtype(TOKEN tok) {
 
  printdebug( "findtype() \n" );

  SYMBOL sym;
  sym = searchst(tok->stringval); 
  
  if(sym->kind == TYPESYM){
    printdebug( "TYPESYM \n" );
    tok->symtype = sym->datatype;
  }
  else if(sym->kind == BASICTYPE ) {
    printdebug( "BASICTYPE \n" );
    tok->symtype = sym; 
    tok->datatype = sym->basicdt;    
  }
  else
    printdebug( "findtype() ERROR \n" );
  

  printdebug( "findtype() ends \n\n" );
  return tok;

}

/*
  *
  *
  *     ASSIGNMENT 5
  *
  *
*/

TOKEN nconc(TOKEN lista, TOKEN listb) {
  
  printdebug( "nconc() \n" );
  TOKEN tmp = lista;
  while( tmp->link )
    tmp = tmp->link;
  tmp->link = listb;

  printdebug( "nconc() ends \n\n" );
  return lista;
  
}
TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement) {
  
  printdebug( "makewhile() \n" );
  TOKEN labeltok = talloc();
  labeltok->tokentype = OPERATOR;
  labeltok->whichval = LABELOP;

  TOKEN numtok = talloc();
  numtok->tokentype = NUMBERTOK;
  numtok->intval = labelnumber++;
  labeltok->operands = numtok;

  TOKEN progntok = makeprogn(tok, labeltok);

  TOKEN iftok = talloc();
  iftok->tokentype = OPERATOR;
  iftok->whichval = IFOP;

  TOKEN iftest = unaryop(iftok, expr);
  labeltok->link = iftok;
  iftest->operands->link = statement;

  TOKEN tmp = statement->operands;
  while(tmp->link)
    tmp = tmp->link;
  
  TOKEN gototok = talloc();
  gototok->tokentype = OPERATOR;
  gototok->whichval = GOTOOP;

  TOKEN gotonum = copytok(numtok);
  tmp->link = unaryop(gototok, gotonum);

  printdebug( "makewhile() ends \n\n" );
  return progntok;

}
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
  
  printdebug( "reducedot() \n" );
  SYMBOL record = var->symtype;
  bool p = false;
  
  if (record->kind == POINTERSYM) {
    record = record->datatype;
    record = stype(record);
    p = true;
  }

  int oldoff = 0;
  bool reuse = false;

  if (!p && var->tokentype == OPERATOR && var->operands->link->tokentype == NUMBERTOK && var->whichval == AREFOP) {
    dot = var;
    oldoff = var->operands->link->intval;
    reuse = true;
  }
  else 
    dot = createtok(OPERATOR,AREFOP);
  
  record = record->datatype;

  while ( record != NULL && strcmp(field->stringval, record->namestring) ) 
    record = record->link;
  
  dot->datatype = record->basicdt;
  int off = record->offset + oldoff;

  if( !p && off == 0 )
    return var;

  if ( !reuse )
    dot->operands = var;

  dot->operands->link = makeintc(off);
  dot->symtype = stype(record->datatype);
    
  printdebug( "reducedot() ends \n\n" );
  return dot;

}
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
  
  printdebug( "arrayref() \n" );
  int index = 0;
  int offset = 0;
  SYMBOL array = arr->symtype;
  TOKEN offsetTok = NULL;
  TOKEN last = NULL;

  while(subs != NULL) {
    TOKEN link = subs->link;
    int size = array->datatype->size;

    TOKEN mult = binop( createtok(OPERATOR,TIMESOP), makeintc(size), subs );
    TOKEN add = binop( createtok(OPERATOR,PLUSOP), makeintc(-size * array->lowbound), mult );

    if(offsetTok != NULL) {
      TOKEN addlast = binop(createtok(OPERATOR,PLUSOP), offsetTok, add);
      offsetTok = addlast;
    }
    else
      offsetTok = add;
    
    array = array->datatype;
    subs = link;
  }

  TOKEN ret = createtok( OPERATOR,AREFOP );
  array = stype( array );
  ret->operands = arr;
  ret->operands->link = offsetTok;
  ret->symtype = array;

  printdebug( "arrayref() ends \n\n" );
  return ret;

}
SYMBOL stype(SYMBOL sym) {
  
  printdebug( "stype() \n" );
  while(sym->kind == TYPESYM)
    sym = sym->datatype;
  
  printdebug( "stype() ends \n\n" );
  return sym;

}
TOKEN copytok(TOKEN tok) {

  printdebug( "copytok() \n" );
  TOKEN ret = talloc();
  *ret = *tok;
  ret->operands = NULL;
  ret->link = NULL;

  printdebug( "copytok() ends \n\n" );
  return ret;

}
TOKEN createtok(int what, int which) {
  
  printdebug( "createtok() \n" );
  TOKEN ret = talloc();
  ret->tokentype = what;
  ret->whichval = which;
  printdebug( "createtok() ends \n\n" );
  return ret;

}
TOKEN instrec(TOKEN rectok, TOKEN argstok) {
  
  printdebug( "instrec() \n" );
  
  SYMBOL tmptab[50];
  TOKEN tmp = argstok;
  
  while(tmp)
    tmp = tmp->link;
  
  SYMBOL tmptable[50];              
  SYMBOL record = makesym( "record" );
  record->kind = RECORDSYM;
  int size = 0;
  
  SYMBOL sym, typesym; 
  int align;
  
  tmp = argstok;
  SYMBOL first;
  typesym = tmp->symtype;
  align = alignsize(typesym);
  int index = 0;
  
  while(tmp) {
    sym = makesym(tmp->stringval);
    if( index == 0 )
      first = sym;
    sym->datatype = tmp->symtype;
    sym->offset += size;
    sym->size = tmp->symtype->size;

    if( (size % 8 != 0) && (tmp->symtype->size == 8) )
      size += 4;
    
    size += tmp->symtype->size;
    tmptab[index] = sym;    
    tmp = tmp->link;
  
    index++;
  }
  
  int i;
  for(i = 0; i < index - 1; i++){
    tmptab[i]->link = tmptab[i+1];
  }
  
  record->datatype = first;
  record->size = size;
  
  rectok->symtype = record;     
  printdebug( "instrec() ends \n\n" );
  return rectok;

}
TOKEN dopoint(TOKEN var, TOKEN tok) {
  
  printdebug( "dopoint() \n" );
  SYMBOL sym = var->symtype;

  tok = createtok(OPERATOR,POINTEROP);
  tok->operands = var;
  sym = stype(sym);
  tok->symtype = sym;

  printdebug( "dopoint() ends \n\n" );
  return tok;

}
TOKEN instfields(TOKEN idlist, TOKEN typetok) {
  
  printdebug( "instfields() \n" );
  TOKEN tmp = idlist;

  while(tmp){
    tmp->symtype = typetok->symtype;
    tmp = tmp->link;
  }
  
//  printf("%s\n", typetok->symtype->namestring);
  printdebug( "instfields() ends \n\n" );
  return idlist;

}
void insttype(TOKEN typename, TOKEN typetok) {
  
  printdebug( "insttype() \n" );

  SYMBOL tmp = searchst(typename->stringval);
  if(tmp) {
    printdebug( " yes!\n" );
    tmp->kind = TYPESYM;
    tmp->datatype = typetok->symtype;
    tmp->size = typetok->symtype->size;
    tmp->basicdt = typetok->symtype->basicdt;
  }
  else {
    printdebug( " no\n" );
    SYMBOL typesym = insertsym(typename->stringval);
    typesym->kind = TYPESYM;
    typesym->datatype = typetok->symtype;
    typesym->size = typetok->symtype->size;
    typesym->basicdt = typetok->symtype->basicdt;
  }

  printdebug( "insttype() ends \n\n" );

}
TOKEN instpoint(TOKEN tok, TOKEN typename) {
  
  printdebug( "instpoint() \n" );
  
  SYMBOL tsym = searchst(typename->stringval);
  if(DEBUG)
    printf("%s\n", typename->stringval);
  SYMBOL tmp = insertsym(typename->stringval);
  tmp->kind = TYPESYM;
  
  
  SYMBOL pointersym = makesym(typename->stringval);   
  pointersym->kind = POINTERSYM;
  pointersym->datatype = tmp;
  pointersym->size = basicsizes[POINTER];
  pointersym->basicdt = POINTER;
  
  if(DEBUG)
    printf("POINTER = %d\n", POINTER);
  
  tok->symtype = pointersym;
  
  if(DEBUG)
    printf("%d\n", tok->symtype->size);

  printdebug( "instpoint() ends \n\n" );
  return tok;

}
TOKEN instenum(TOKEN idlist) {

  printdebug( "instenum() \n" );
  int low = 0, high = 0;
  TOKEN tmp = idlist;
  
  while(tmp){
    tmp = tmp->link;
    high++;
  }
  
  TOKEN subrange = makesubrange(copytok(idlist), low, high - 1);
  
  tmp = idlist;
  TOKEN number = copytok(idlist);
  number->tokentype = NUMBERTOK;
  number->datatype = INTEGER;

  int i;
  for(i = 0; i < high; i++){
    number->intval = i;
    instconst(tmp, number);
    number = copytok(number);
    tmp = tmp->link;
  }
  printdebug( "instenum() ends \n\n" );
  return subrange;

}
TOKEN makesubrange(TOKEN tok, int low, int high){

  printdebug( "makesubrange() \n" );
  SYMBOL subrange = makesym("subrange" );
  subrange->kind = SUBRANGE;
  subrange->highbound = high;
  subrange->lowbound = low;
  subrange->basicdt = INTEGER;
  subrange->size = basicsizes[INTEGER];
  tok->symtype = subrange;
  tok->tokentype = NUMBERTOK;
  printdebug( "makesubrange() ends \n\n" );
  return tok;

}
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement){
  
  printdebug( "dolabel() \n" );
  TOKEN progn = makeprogn(tok, statement);
  TOKEN label = talloc();
  label->tokentype = OPERATOR;
  label->whichval = LABELOP;
  label->operands = labeltok;

  int i = 0;
  while(labels[i] != labeltok->intval)
    i++;
  labeltok->intval = i;
  progn->operands = label;
  label->link = statement;
  printdebug( "dolabel() ends \n\n" );
  return progn;

}
void  instlabel (TOKEN num) {

  printdebug( "instlabel() \n" );
  labels[labelnumber++] = num->intval;
  
  int i;
  for(i = 0; i < labelnumber; i++)
    printf("%d\n", labels[i]);
  
  printdebug( "instlabel() ends \n\n" );

}
TOKEN instarray(TOKEN simpletypes, TOKEN typetok) {

  printdebug( "instarray() \n" );
  SYMBOL sym = instarrayhelper(simpletypes, typetok);

  TOKEN ret = talloc();
  ret->symtype = sym;
  printdebug( "instarray() ends \n\n" );
  return ret;

}
SYMBOL instarrayhelper(TOKEN simpletypes, TOKEN typetok) {
  
  printdebug( "instarrayhelper() \n" );
  if(simpletypes == NULL) 
    return typetok->symtype;

  SYMBOL sym = symalloc();
  SYMBOL simplesym = simpletypes->symtype;
  sym->kind = ARRAYSYM;

  if(simplesym->datatype != NULL) {
    sym->lowbound = simplesym->datatype->lowbound;
    sym->highbound = simplesym->datatype->highbound;
  }

  sym->datatype = instarrayhelper(simpletypes->link, typetok);
  sym->size = (sym->highbound - sym->lowbound + 1)*sym->datatype->size;
  printdebug( "instarrayhelper() ends \n\n" );
  return sym;

}
TOKEN convertnil(TOKEN nil) {

  printdebug( "convertnil() \n" );
  TOKEN zero = talloc();
  zero->tokentype = NUMBERTOK;
  zero->datatype = POINTER;
  zero->intval = 0;
  printdebug( "convertnil() ends \n\n" );
  return zero;

}

/*
  *
  *
  *     ORIGINAL CODE
  *
  *
*/

void printdebug (char arr[]) {
  
  char array[sizeof(arr) + 1];
  int i;
  for (i = 0; i < sizeof(arr); i++)
    array[i] = arr[i];
  array[sizeof(arr)] = '\0';

  if (DEBUG)
    printf("%s", arr);
  
}
int wordaddress(int n, int wordsize) {
  return ((n + wordsize - 1) / wordsize) * wordsize;
}
yyerror(s) char * s; {
  extern int yylineno;  // defined and maintained in lex
  extern char *yytext;  // defined and maintained in lex
  fprintf(stderr, "ERROR: %s at symbol '%s' on line %d\n", s, yytext, yylineno);
  fputs(s, stderr);
  putc('\n', stderr);
}
main() {
  int res;
  initsyms();
  res = yyparse();
  printst();
  printf("yyparse result = %8d\n", res);
  if (DEBUG) 
    dbugprinttok(parseresult);
  ppexpr(parseresult); /* Pretty-print the result tree */
}