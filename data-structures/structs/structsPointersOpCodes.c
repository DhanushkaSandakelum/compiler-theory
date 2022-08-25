#include <stdio.h>
#include <string.h>

enum code_ops {
	HALT, STORE, JMP_FALSE,GOTO,
	DATA, LD_INT, LD_VAR,
	READ_INT, WRITE_INT,
	LT , EQ, GT, ADD, SUB, MULT, DIV, PWR
};

struct pair {
	char code[15];
	enum code_ops op_code;
};

struct pair codes[] = {
	{"halt", HALT}, {"store", STORE}
};

int main () {
	int count = sizeof(codes)/sizeof(codes[0]);
	
	int i  = 0;
	
	for(i = 0; i < count; i++){
		printf("Code: %s OpCode: %d\n", codes[i].code, codes[i].op_code);
	}
}
