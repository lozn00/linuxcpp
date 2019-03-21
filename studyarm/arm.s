	.file	"arm.c"
	.text
	.globl	myFunctiontrue1
	.type	myFunctiontrue1, @function
myFunctiontrue1:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	myFunctiontrue1, .-myFunctiontrue1
	.globl	myFunctionfalse1
	.type	myFunctionfalse1, @function
myFunctionfalse1:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	myFunctionfalse1, .-myFunctionfalse1
	.globl	myFunctiontrue2
	.type	myFunctiontrue2, @function
myFunctiontrue2:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	myFunctiontrue2, .-myFunctiontrue2
	.globl	myFunctionfalse2
	.type	myFunctionfalse2, @function
myFunctionfalse2:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	myFunctionfalse2, .-myFunctionfalse2
	.globl	myFunctiontrue3
	.type	myFunctiontrue3, @function
myFunctiontrue3:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	myFunctiontrue3, .-myFunctiontrue3
	.globl	myFunctionfalse3
	.type	myFunctionfalse3, @function
myFunctionfalse3:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	myFunctionfalse3, .-myFunctionfalse3
	.globl	myFunctiontrue4
	.type	myFunctiontrue4, @function
myFunctiontrue4:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	myFunctiontrue4, .-myFunctiontrue4
	.globl	myFunctionfalse4
	.type	myFunctionfalse4, @function
myFunctionfalse4:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	myFunctionfalse4, .-myFunctionfalse4
	.globl	myFunctiontrue5
	.type	myFunctiontrue5, @function
myFunctiontrue5:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	myFunctiontrue5, .-myFunctiontrue5
	.globl	myFunctionfalse5
	.type	myFunctionfalse5, @function
myFunctionfalse5:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	myFunctionfalse5, .-myFunctionfalse5
	.globl	myfunc6True
	.type	myfunc6True, @function
myfunc6True:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	call	rand
	movslq	%eax, %rbx
	movl	$0, %edi
	call	time
	movq	%rax, %rcx
	movq	%rbx, %rax
	cqto
	idivq	%rcx
	movq	%rdx, %rax
	movl	%eax, -20(%rbp)
	cmpl	$10, -20(%rbp)
	jle	.L12
	movl	$20, %eax
	jmp	.L13
.L12:
	movl	$1, %eax
.L13:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	myfunc6True, .-myfunc6True
	.section	.rodata
.LC0:
	.string	"hello random %d\n"
.LC1:
	.string	"%d<10, gotb ++\n"
.LC2:
	.string	"%d<15, gotb ++ \n"
.LC3:
	.string	" end %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	call	rand
	movslq	%eax, %rbx
	movl	$0, %edi
	call	time
	movq	%rax, %rcx
	movq	%rbx, %rax
	cqto
	idivq	%rcx
	movq	%rdx, %rax
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	-36(%rbp), %eax
	movl	%eax, -32(%rbp)
	movl	$2, -28(%rbp)
	movl	$5, -40(%rbp)
.L15:
	movl	-32(%rbp), %eax
	subl	$2, %eax
	cmpl	$2, %eax
	jle	.L16
	movl	$0, %eax
	call	myFunctiontrue1
	jmp	.L17 //直接执行.L17 .L17是主程序的部分代码
.L16:
	movl	$0, %eax
	call	myFunctionfalse1 //s顺序执行
.L17:
	movl	-32(%rbp), %eax
	subl	$2, %eax
	cmpl	$2, %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -24(%rbp)
	cmpl	$0, -24(%rbp)
	je	.L18 //成立就跳转到 L18 下面 不会走
	movl	$0, %eax
	call	myFunctiontrue2
	jmp	.L19
.L18:
	movl	$0, %eax
	call	myFunctionfalse2
.L19:
	movl	-32(%rbp), %eax
	subl	$2, %eax
	cmpl	$2, %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -24(%rbp)
	cmpl	$5, -24(%rbp)
	jle	.L20
	movl	$0, %eax
	call	myFunctiontrue3
	jmp	.L21
.L20:
	movl	$0, %eax
	call	myFunctionfalse3
.L21:
	movl	-32(%rbp), %eax
	subl	$2, %eax
	cmpl	$2, %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -24(%rbp)
	cmpl	$4, -24(%rbp)
	jg	.L22
	movl	$0, %eax
	call	myFunctiontrue4
	jmp	.L23
.L22:
	movl	$0, %eax
	call	myFunctionfalse4
.L23:
	cmpl	$5, -24(%rbp)
	jg	.L24
	cmpl	$1, -24(%rbp)
	jg	.L25
.L24:
	movl	$0, %eax
	call	myFunctiontrue5
.L25:
	movl	$0, %eax
	call	myfunc6True
	movl	%eax, -20(%rbp) //取返回值
.L26:
	addl	$1, -40(%rbp)
	cmpl	$9, -40(%rbp)
	jg	.L27
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L26
.L27:
	cmpl	$14, -40(%rbp)
	jg	.L28
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L26
.L28:
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
