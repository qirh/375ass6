#program graph1(output);
#const d = 0.0625; {1/16, 16 lines for interval [x,x+1]}
#      s = 32; {32 character widths for interval [y,y+1]}
#      h = 34; {character position of x-axis}
#      c = 6.28318; {2*pi}  lim = 32;
#var x,y : real;  i,n : integer;
#begin
#   for i := 0 to lim do
#      begin x := d*i; y := exp(-x)*sin(c*x);
#      n := round(s*y) + h;
#      repeat write(' ');  n := n-1
#      until n=0;
#      writeln('*')
#   end
#end.
#
#Symbol table level 1
# 27540240         lim  CONST  typ INTEGER  val  32
# 27540368           c  CONST  typ    REAL  val  6.283180e+00
# 27540496           h  CONST  typ INTEGER  val  34
# 27540624           s  CONST  typ INTEGER  val  32
# 27540752           d  CONST  typ    REAL  val  6.250000e-02
# 27541360           x  VAR    1 typ    real  lvl  1  siz     8  off     0
# 27541488           y  VAR    1 typ    real  lvl  1  siz     8  off     8
# 27542192           i  VAR    0 typ integer  lvl  1  siz     4  off    16
# 27542320           n  VAR    0 typ integer  lvl  1  siz     4  off    20
#yyparse result =        0
#(program graph1 (progn output)
#                (progn (:= i 0)
#                       (label 1)
#                       (if (<= i 32)
#                           (progn (:= x (* 6.250000e-02
#                                           (float i)))
#                                  (:= y (* (funcall exp (- x))
#                                           (funcall sin (* 6.283180e+00
#                                                           x))))
#                                  (:= n (fix (+ (funcall round (* 3.200002e+01
#                                                                  y))
#                                                3.400002e+01)))
#                                  (progn (label 0)
#                                         (funcall write ' ')
#                                         (:= n (- n 1))
#                                         (if (= n 0)
#                                             (progn)
#                                             (goto 0)))
#                                  (funcall writeln '*')
#                                  (:= i (+ i 1))
#                                  (goto 1)))))

# ---------------- Beginning of Generated Code --------------------
        .file   "foo"
        .text
.globl graph1
        .type   graph1, @function
graph1:

.LFB0:
	.cfi_startproc
	pushq	%rbp              # save base pointer on stack
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp        # move stack pointer to base pointer
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
        subq	$48, %rsp 	  # make space for this stack frame
	movq	%rbx, %r9        # save %rbx (callee-saved) in %r9
# ------------------------- begin Your code -----------------------------
	movl	$0,%eax         	#  0 -> %eax
	movl	%eax,-32(%rbp)     	#  %eax -> i
.L1:
	movl	-32(%rbp),%eax     	#  i -> %eax
	movl	$32,%ecx         	#  32 -> %ecx
	cmpl	%ecx,%eax           	#  compare %eax - %ecx
	jle	.L3 			#  jump if     <=
	jmp	.L4 			#  jump 
.L3:
	movsd	.LC5(%rip),%xmm0   	#  0.062500 -> %xmm0
	movl	-32(%rbp),%eax     	#  i -> %eax
	cvtsi2sd	%eax,%xmm1    	#  float %eax -> %xmm1
	mulsd	%xmm1,%xmm0         	#  %xmm0 * %xmm1 -> %xmm0
	movsd	%xmm0,-48(%rbp)     	#  %xmm0 -> x
	movsd	-48(%rbp),%xmm0     	#  x -> %xmm0
	movsd	.LC666(%rip),%xmm1   	#  0.000000 -> %xmm1
	xorpd	%xmm1,%xmm0           	#  negate %xmm0
	call	exp              	#  exp()
	movsd	%xmm0,-8(%rbp)     	#  %xmm0 -> temp
	movsd	.LC6(%rip),%xmm0   	#  6.283180 -> %xmm0
	movsd	-48(%rbp),%xmm1     	#  x -> %xmm1
	mulsd	%xmm1,%xmm0         	#  %xmm0 * %xmm1 -> %xmm0
	call	sin              	#  sin()
	movsd	-8(%rbp),%xmm1     	#  temp -> %xmm1
	mulsd	%xmm0,%xmm1         	#  %xmm1 * %xmm0 -> %xmm1
	movsd	%xmm1,-40(%rbp)     	#  %xmm1 -> y
	movsd	.LC7(%rip),%xmm0   	#  32.000000 -> %xmm0
	movsd	-40(%rbp),%xmm1     	#  y -> %xmm1
	mulsd	%xmm1,%xmm0         	#  %xmm0 * %xmm1 -> %xmm0
	call	round              	#  round()
	movsd	.LC8(%rip),%xmm1   	#  34.000000 -> %xmm1
	addsd	%xmm1,%xmm0         	#  %xmm0 + %xmm1 -> %xmm0
	cvttsd2si	%xmm0,%eax    	#  fix %xmm0 -> %eax
	movl	%eax,-28(%rbp)     	#  %eax -> n
.L0:
	movl	$.LC9,%edi       	#  addr of literal .LC9
	call	write              	#  write()
	movl	-28(%rbp),%eax     	#  n -> %eax
	movl	$1,%ecx         	#  1 -> %ecx
	subl	%ecx,%eax         	#  %eax - %ecx -> %eax
	movl	%eax,-28(%rbp)     	#  %eax -> n
	movl	-28(%rbp),%eax     	#  n -> %eax
	movl	$0,%ecx         	#  0 -> %ecx
	cmpl	%ecx,%eax           	#  compare %eax - %ecx
	je	.L10 			#  jump if     ==
	jmp	.L0 			#  jump 
	jmp	.L11 			#  jump 
.L10:
.L11:
	movl	$.LC12,%edi       	#  addr of literal .LC12
	call	writeln              	#  writeln()
	movl	-32(%rbp),%eax     	#  i -> %eax
	movl	$1,%ecx         	#  1 -> %ecx
	addl	%ecx,%eax         	#  %eax + %ecx -> %eax
	movl	%eax,-32(%rbp)     	#  %eax -> i
	jmp	.L1 			#  jump 
.L4:
# ----------------------- begin Epilogue code ---------------------------
	movq	%r9, %rbx        # restore %rbx (callee-saved) from %r9
        leave
        ret
        .cfi_endproc
.LFE0:
        .size   graph1, .-graph1
# ----------------- end Epilogue; Literal data follows ------------------
        .section        .rodata
	.align 16
.LC666:                    # constant for floating negation
	.long	0
	.long	-2147483648
	.long	0
	.long	0
	.align  4
.LC9:
	.string	" "
	.align  4
.LC12:
	.string	"*"
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
	.long	0   	#  32.000000
	.long	1077936128
	.align  8
.LC8:
	.long	0   	#  34.000000
	.long	1078001664

        .ident  "CS 375 Compiler - Summer 2013"
