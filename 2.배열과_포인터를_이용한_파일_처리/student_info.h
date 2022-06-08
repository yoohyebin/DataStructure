#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student_info {
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];
}student_info;
