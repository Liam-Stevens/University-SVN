// let x = 1;
	@x
	M=1
// let y = 10;
	@10
	D=A
	@y
	M=D
// let sum = x + y;
	@sum
	M=D
	@x
	D=M
	@sum
	M=M+D

(END)
	@END
	0;JMP
