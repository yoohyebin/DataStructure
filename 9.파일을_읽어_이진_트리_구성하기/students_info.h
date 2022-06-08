#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct treeNode {
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];
	struct _treeNode* left;
	struct _treeNode* right;
}treeNode;
