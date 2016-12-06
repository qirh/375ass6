Name:		
Email:		
EID:		
CS Login:	

Lab 4 - Code Generator
Due 14/08/15 by 2359

Required Files

	Modified/new files
		- codegen.c
		- codegen.h
		- parse.y

	Required from Lab 3 P3
		- lexan.*
		- parse.h
		- pprint.c
		- printtoken.c
		- symtab.*
		- token.h

	Files req'd from /projects/CS375/
		- driver.c
		- genasm.*
		- makefile
		- test files: trivb.pas, graph1.pas, and pasrec.pas

Changelog
	
	- codegen.c: 	added errythanggg
	- codegen.h:	added include statement for boolean type
					added various helper methods for codegen.c
					renamed some of the default methods
	- parse.y: 		added line at end of main() to enable code generation
					added a few record-searching methods THAT ARE BROKEN

Optimizations (if any)

	- 	handling array references is simplified by the optimization
		performed in parse.y that enables all subtrees for arrays
		to have the same structure (no recursive traversal req'd)

Run Instructions

	1) Place all required files into directory

	2) Run trivbtest, graph1test, or pasrectest

	OR

	2) make compiler

		3) compiler < [test file]

		OR

		3) compiler < [test file] > [test file].s
	   		a) cc driver.c [test file].s -lm
	   		b) a.out

Notes

	- In the Epilogue, any float that was not rounded off to exactly
	  0 means that -INT_MAX will print instead of 0, eg

	  .long	-2147483648		# 3.000001

	  instead of

	  .long	0				# 3.000000

	  This does not affect the output code generated.

	- Arrays of only max 2 dimensions are supported.

Bugs

	- no known program-crashing bugs

TODO

	- record-searching methods in parse.y are broken; DO NOT USE
	- anywhere in codegen.c where there are a billion question marks
		- usually means that error-checking is required and a graceful
		  means of exiting the program should be written in
	- patch up all memory leaks occurring in codegen.c (parse.y
	  and lexan.c have already been patched)
	- expand the FUNCALLOP else if() and AREFOP else if() statements in
	  genop() to handle arrays of more than 2 dimensions (up to 10 are
	  handled in arrayref() in parse.y)
	- change all tests for register type (general purpose, FP, etc) to use
	  is_gen_purpose_reg() and is_fp_reg() instead of the long if() statements

Other





