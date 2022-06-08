#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct MQ_Node {
	char* message;
	time_t start_time;
	struct MQ_Node* next;
} MQ_Node;

typedef struct _LinkedQueue {
	MQ_Node* front;
	MQ_Node* rear;
} LinkedQueue;
