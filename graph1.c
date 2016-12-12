# ---------------- Beginning of Generated Code --------------------
        .file   "foo"
        .text
.globl graph1
        .type   graph1, @function
graph1:
.LFB0:
 .cfi_startproc
 pushq %rbp              # save base pointer on stack
 .cfi_def_cfa_offset 16
 movq  %rsp, %rbp        # move stack pointer to base pointer
 .cfi_offset 6, -16
 .cfi_def_cfa_register 6
        subq	$48, %rsp 	  # make space for this stack frame
 movq  %rbx, %r9        # save %rbx (callee-saved) in %r9
# ------------------------- begin Your code -----------------------------
genc
 token 22802576  OP         progn  dtype  0  link 0  operands 22795568
genc
 token 22795568  OP            :=  dtype  0  link 22802672  operands 22795472
testgenarith
 token 22795664  NUM            0  dtype  0  link 0
getreg
0
	movl	$0,%eax         	#  0 -> %eax
	movl	%eax,-32(%rbp)     	#  %eax -> i
genc
 token 22802672  OP         label  dtype  0  link 22803056  operands 22802768
test3.L1:
genc
 token 22803056  OP            if  dtype  0  link 0  operands 22802864
test4genarith
 token 22802864  OP            <=  dtype  0  link 22796048  operands 22803152
genarith
 token 22803152  ID             i  dtype  0  link 22795856
getreg
0
	movl	-32(%rbp),%eax     	#  i -> %eax
genarith
 token 22795856  NUM           32  dtype  0  link 0
getreg
0
	movl	$32,%ecx         	#  32 -> %ecx
	cmpl	%ecx,%eax           	#  compare %eax - %ecx
	jle	.L3 			#  jump if     <=
	jmp	.L4 			#  jump 
.L3:
genc
 token 22796048  OP         progn  dtype  0  link 0  operands 22796240
genc
 token 22796240  OP            :=  dtype  1  link 22796912  operands 22796144
testgenarith
 token 22796432  OP             *  dtype  1  link 0  operands 22796336
genarith
 token 22796336  NUM 6.250000e-02  dtype  1  link 22796720
getreg
1
	movsd	.LC5(%rip),%xmm0   	#  0.062500 -> %xmm0
genarith
 token 22796720  OP         float  dtype  0  link 0  operands 22796528
genarith
 token 22796528  ID             i  dtype  0  link 0
getreg
0
	movl	-32(%rbp),%eax     	#  i -> %eax
getreg
0
getreg
1
	cvtsi2sd	%eax,%xmm1    	#  float %eax -> %xmm1
getreg
1
	mulsd	%xmm1,%xmm0         	#  %xmm0 * %xmm1 -> %xmm0
	movsd	%xmm0,-48(%rbp)     	#  %xmm0 -> x
genc
 token 22796912  OP            :=  dtype  1  link 22798544  operands 22796816
testgenarith
 token 22797584  OP             *  dtype  1  link 0  operands 22797488
genarith
 token 22797488  OP       funcall  dtype  1  link 22798256  operands 22797008
genarith
 token 22797008  ID           exp  dtype  0  link 22797200
getreg
1
genc
 token 22797200  OP             -  dtype  0  link 0  operands 22797296
test5genarith
 token 22797200  OP             -  dtype  0  link 0  operands 22797296
genarith
 token 22797296  ID             x  dtype  1  link 0
getreg
1
	movl	-48(%rbp),%xmm0     	#  x -> %xmm0
getreg
1
	movsd	.LC666(%rip),%xmm1   	#  0.000000 -> %xmm1
	xorpd	%xmm1,%xmm0           	#  negate %xmm0
getreg
1
	call	exp              	#  exp()
	movsd	%xmm0,-8(%rbp)     	#  %xmm0 -> temp
getreg
1
genarith
 token 22798256  OP       funcall  dtype  1  link 0  operands 22797680
genarith
 token 22797680  ID           sin  dtype  0  link 22797968
getreg
1
genc
 token 22797968  OP             *  dtype  1  link 0  operands 22797872
test5genarith
 token 22797968  OP             *  dtype  1  link 0  operands 22797872
genarith
 token 22797872  NUM 6.283180e+00  dtype  1  link 22798064
getreg
1
	movsd	.LC6(%rip),%xmm0   	#  6.283180 -> %xmm0
genarith
 token 22798064  ID             x  dtype  1  link 0
getreg
1
	movl	-48(%rbp),%xmm1     	#  x -> %xmm1
	mulsd	%xmm1,%xmm0         	#  %xmm0 * %xmm1 -> %xmm0
	call	sin              	#  sin()
	movsd	-8(%rbp),%xmm1     	#  temp -> %xmm1
	mulsd	%xmm0,%xmm1         	#  %xmm1 * %xmm0 -> %xmm1
	movsd	%xmm1,-40(%rbp)     	#  %xmm1 -> y
genc
 token 22798544  OP            :=  dtype  1  link 22801712  operands 22798448
testgenarith
 token 22799600  OP           fix  dtype  0  link 0  operands 22799312
genarith
 token 22799312  OP             +  dtype  1  link 0  operands 22799216
genarith
 token 22799216  OP       funcall  dtype  1  link 22799408  operands 22798640
genarith
 token 22798640  ID         round  dtype  0  link 22798928
getreg
1
genc
 token 22798928  OP             *  dtype  1  link 0  operands 22798832
test5genarith
 token 22798928  OP             *  dtype  1  link 0  operands 22798832
genarith
 token 22798832  NUM 3.200002e+01  dtype  1  link 22799024
getreg
1
	movsd	.LC7(%rip),%xmm0   	#  32.000015 -> %xmm0
genarith
 token 22799024  ID             y  dtype  1  link 0
getreg
1
	movl	-40(%rbp),%xmm1     	#  y -> %xmm1
	mulsd	%xmm1,%xmm0         	#  %xmm0 * %xmm1 -> %xmm0
getreg
1
	call	round              	#  round()
getreg
1
genarith
 token 22799408  NUM 3.400002e+01  dtype  1  link 0
getreg
1
	movsd	.LC8(%rip),%xmm1   	#  34.000015 -> %xmm1
getreg
1
	addsd	%xmm1,%xmm0         	#  %xmm0 + %xmm1 -> %xmm0
getreg
1
getreg
0
	cvttsd2si	%xmm0,%eax    	#  fix %xmm0 -> %eax
	movl	%eax,-28(%rbp)     	#  %eax -> n
genc
 token 22801712  OP         progn  dtype  0  link 22802480  operands 22801328
genc
 token 22801328  OP         label  dtype  0  link 22800272  operands 22801424
test3.L0:
genc
 token 22800272  OP       funcall  dtype  0  link 22800464  operands 22799792
test5genc
 token 22800464  OP            :=  dtype  0  link 22801904  operands 22800368
testgenarith
 token 22800656  OP             -  dtype  0  link 0  operands 22800560
genarith
 token 22800560  ID             n  dtype  0  link 22800752
getreg
0
	movl	-28(%rbp),%eax     	#  n -> %eax
genarith
 token 22800752  NUM            1  dtype  0  link 0
getreg
0
	subl	%ecx,%eax         	#  %eax - %ecx -> %eax
	movl	%eax,-28(%rbp)     	#  %eax -> n
genc
 token 22801904  OP            if  dtype  0  link 0  operands 22801040
test4genarith
 token 22801040  OP             =  dtype  0  link 22801808  operands 22800944
genarith
 token 22800944  ID             n  dtype  0  link 22801136
getreg
0
	movl	-28(%rbp),%eax     	#  n -> %eax
genarith
 token 22801136  NUM            0  dtype  0  link 0
getreg
0
	cmpl	%ecx,%eax           	#  compare %eax - %ecx
	je	.L9 			#  jump if     ==
	jmp	.L0 			#  jump 
	jmp	.L10 			#  jump 
.L9:
genc
 token 22801808  OP         progn  dtype  0  link 22801520  operands 0
.L10:
genc
 token 22801040  OP             =  dtype  0  link 22801808  operands 22800944
test5genc
 token 22802480  OP       funcall  dtype  0  link 22803248  operands 22802000
test5genc
 token 22803248  OP            :=  dtype  0  link 22803728  operands 22803344
testgenarith
 token 22803632  OP             +  dtype  0  link 0  operands 22803536
genarith
 token 22803536  ID             i  dtype  0  link 22803440
getreg
0
	movl	-32(%rbp),%eax     	#  i -> %eax
genarith
 token 22803440  NUM            1  dtype  0  link 0
getreg
0
	addl	%ecx,%eax         	#  %eax + %ecx -> %eax
	movl	%eax,-32(%rbp)     	#  %eax -> i
genc
 token 22803728  OP          goto  dtype  0  link 0  operands 22803824
test2	jmp	.L1 			#  jump 
.L4:
genc
 token 22802864  OP            <=  dtype  0  link 22796048  operands 22803152
test5# ----------------------- begin Epilogue code ---------------------------
 movq  %r9, %rbx        # restore %rbx (callee-saved) from %r9
        leave
        ret
        .cfi_endproc
.LFE0:
        .size   graph1, .-graph1
# ----------------- end Epilogue; Literal data follows ------------------
        .section        .rodata
 .align 16
.LC666:                    # constant for floating negation
 .long 0
 .long -2147483648
 .long 0
 .long 0
	.align  8
.LC5:
	.long	0   	#  0.062500
	.long	1068498944
	.align  8
.LC6:
	.long	0   	#  6.283180
	.long	1075388922
	.align  8
.LC7:
	.long	-2147483648   	#  32.000015
	.long	1077936128
	.align  8
.LC8:
	.long	-2147483648   	#  34.000015
	.long	1078001664

        .ident  "CS 375 Compiler - Spring 2016"
