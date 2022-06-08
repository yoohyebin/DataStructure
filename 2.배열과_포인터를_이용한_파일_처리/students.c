#define _CRT_SECURE_NO_WARNINGS
#include "student_info.h"

int main() {

	FILE* fp = fopen("students.txt", "r");
	char line[256];
	char a[5];
	int i = 0, n = 0, j=0, k=0;
	while (!feof(fp))
	{
		fgets(line, 256, fp);
		n++;
	}

	student_info* s = malloc(sizeof(student_info) * n);
	rewind(fp);

	while (!feof(fp))
	{
		if (i != 0)
			fscanf(fp, "%s	%c	%s	%c	%s	%s\n", s[i].student_id, &s[i].department_id, s[i].department_name, &s[i].grade, s[i].name, s[i].birthday);
		if (i == 0)
			fgets(line, 256, fp);
		i++;
	}
	fclose(fp);

	while (1)
	{
		printf("-------------------------------------------------\n");
		printf("> 출력을 원하는 컬럼(c) 또는  레코드(r)를 입력하세요. a를 누르면 모든 데이터가 출력됩니다.quit를 입력하면 종료합니다.\n");
		scanf("%s", a);
		if (a[0] == 'a')
		{
			for (j = 1; j < i; j++)
				printf("%d. %s	%c	%s	%c	%s	%s\n", j, s[j].student_id, s[j].department_id, s[j].department_name, s[j].grade, s[j].name, s[j].birthday);
		}
		else if (a[0] == 'c')
		{
			printf("Usage: c [1~5] (1: 학번, 2: 학과, 3: 학년, 4: 이름, 5: 생년월일\n");
			scanf("%d", &k);
			switch (k)
			{
			case 1:
				for (j = 1; j < i; j++)
					printf("%s\n", s[j].student_id);
				break;
			case 2:
				for (j = 1; j < i; j++)
					printf("%s\n", s[j].department_name);
				break;
			case 3:
				for (j = 1; j < i; j++)
					printf("%c\n", s[j].grade);
				break;
			case 4:
				for (j = 1; j < i; j++)
					printf("%s\n", s[j].name);
				break;
			case 5:
				for (j = 1; j < i; j++)
					printf("%s\n", s[j].birthday);
				break;
			}
		}
		else if (a[0] == 'r')
		{
			scanf("%d", &k);
			printf("%s	%c	%s	%c	%s	%s\n", s[k].student_id, s[k].department_id, s[k].department_name, s[k].grade, s[k].name, s[k].birthday);
		}
		else if (strcmp(a, "quit") == 0)
		{
			printf("\n종료\n");
			break;
		}
		else
			printf("다시 입력하세요.\n");
	}
	free(s);
}
