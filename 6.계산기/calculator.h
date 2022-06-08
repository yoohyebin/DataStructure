#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
	union item {
		int operand;
		char operator;
	}item;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode* top;
}LinkedStack;
