#include "student_info.h"

void insert(Node** phead, Node* newnode)
{
	Node* ptr = *phead;
	Node* tail = NULL;
	Node* p = NULL;
	if (*phead == NULL)	//연결리스트에 아무 내용이 없을때
	{
		(*phead) = newnode;
		(*phead)->next = NULL;
		(*phead)->prev = NULL;
	}
	else
	{
		while (ptr != NULL)	//마지막 노드의 주소값을 찾는 반복문
		{
			p = ptr;
			ptr = ptr->next;
		}
		ptr = newnode;
		p->next = ptr;	//연결리스트의 끝에 newnode를 
		ptr->prev = p;
		tail = ptr;
		tail->next = NULL;
		tail->prev = p;
	}
}
void delete(Node** phead, Node* remove)
{
	Node* p = NULL;
	for (p = *phead; p != NULL; p = p->next) //node의 처음부터 마지막 node까
	{
		if (p == remove) //지우려고하는 정보의 주소와 같을때
		{
			if (p->next == NULL) //지우려는 정보가 마지막이면
				p->prev->next = NULL; //지우려는 정보 앞의 다음을 NULL로 지정
			else if (p == *phead)
				*phead = p->next;
			else
			{
				p->prev->next = p->next; //지우려는 정보 앞의 다음을 지우려는 정보의 다음으로 지정
			}
		}
	}
}

Node* createnode(void)
{
	Node* newnode = (Node*)malloc(sizeof(Node)); //새로운 노드 생성
	printf("추가할 학생 정보를 입력하세요(ex. 201721366 1 security 2 hyebin 1999-02-18)\n");
	scanf("%s	%c	%s	%c	%s	%s", newnode->student_id, &newnode->department_id, newnode->department_name, &newnode->grade, newnode->name, newnode->birthday);
	newnode->next = NULL;
	return newnode; //newnode의 주소값 반환
}

int main()
{
	int menu = 0, a = 0, i = 0, n = 0, j = 0, count = 0;
	char q[50], line[256];
	Node* head = NULL; //첫번째 node
	Node* curr = NULL; //현재 node
	Node* se = (Node*)malloc(sizeof(Node));
	FILE* fp = fopen("students_10.txt", "rt"); //파일 읽기

	while (!feof(fp)) //학생수
	{
		fgets(line, 256, fp);
		n++;
	}
	rewind(fp);

	while (!feof(fp))
	{
		if (i != 0)
		{
			Node* newnode = (Node*)malloc(sizeof(Node)); //새로운 node생성
			newnode->next = NULL;
			fscanf(fp, "%s	%c	%s	%c	%s	%s\n", newnode->student_id, &newnode->department_id, newnode->department_name, &newnode->grade, newnode->name, newnode->birthday);
			insert(&head, newnode);
		}
		if (i == 0)
			fgets(line, 256, fp);
		i++;
	}
	while (1)
	{
		count = 0;
		printf("원하는 기능을 입력하세요(1:검색 2:추가 3:삭제 4:전체출력 5:종료)\n");
		scanf("%d", &menu);
		switch (menu) //switch문을 이용해 메뉴 선택
		{
		case 1:
			printf("검색할 필드명(1:학번 2:성명 3:학과 4:학년 5:생년월일)과 검색어를 입력하세요.\n");
			scanf("%d", &a);
			scanf("%s", q);
			//원하는 정보 찾기
			if (a == 1)
			{
				for (curr = head; curr != NULL; curr = curr->next)
				{
					if (strcmp(curr->student_id, q) == 0)
					{
						printf("%s	%c	%s	%c	%s	%s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						count++;
					}
				}
				printf("\n총: %d 명\n", count);
			}
			else if (a == 2)
			{
				for (curr = head; curr != NULL; curr = curr->next)
				{
					if (strcmp(curr->name, q) == 0)
					{
						printf("%s	%c	%s	%c	%s	%s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						count++;
					}
				}
				printf("\n총: %d 명\n", count);
			}
			else if (a == 3)
			{
				for (curr = head; curr != NULL; curr = curr->next)
				{
					if (strcmp(curr->name, q) == 0)
					{
						printf("%s	%c	%s	%c	%s	%s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						count++;
					}
				}
				printf("\n총: %d 명\n", count);
			}
			else if (a == 4)
			{
				for (curr = head; curr != NULL; curr = curr->next)
				{
					if (strcmp(curr->name, q) == 0)
					{
						printf("%s	%c	%s	%c	%s	%s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						count++;
					}
					printf("\n총: %d 명\n", count);
				}
			}
			else if (a == 5)
			{
				for (curr = head; curr != NULL; curr = curr->next)
				{
					if (strcmp(curr->name, q) == 0)
					{
						printf("%s	%c	%s	%c	%s	%s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
						count++;
					}
					printf("\n총: %d 명\n", count);
				}
			}
			else {
				printf("잘못 입력하셨습니다");
			}
			break;
		case 2:
			insert(&head, createnode());
			break;
		case 3:
			se = head;
			printf("삭제할 학생 정보를 입력하세요(1:학번 2:성명 3:학과 4:학년 5:생년월일)\n");
			scanf("%d", &a);
			scanf("%s", q);
			//원하는 정보찾기
			if (a == 1)
			{
				while (se != NULL) {
					if (strcmp(se->student_id, q) == 0)
						delete(&head, se);
					se = se->next;
				}
			}
			else if (a == 2)
			{
				while (se != NULL) {
					if (strcmp(se->name, q) == 0)
						delete(&head, se);
					se = se->next;
				}
			}
			else if (a == 3)
			{
				while (se != NULL) {
					if (strcmp(se->department_name, q) == 0)
						delete(&head, se);
					se = se->next;
				}
			}
			else if (a == 4)
			{
				while (se != NULL) {
					if (se->grade == q[0])
						delete(&head, se);
					se = se->next;
				}
			}
			else if (a == 5)
			{
				while (se != NULL) {
					if (strcmp(se->birthday, q) == 0)
						delete(&head, se);
					se = se->next;
				}
			}
			else {
				printf("잘못 입력하셨습니다");
			}
			break;
		case 4:
			for (curr = head; curr != NULL; curr = curr->next)
			{
				printf("%s	%c	%s	%c	%s	%s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
				count++;
			}
			printf("\n총: %d 명\n", count);
			break;
		case 5:
			printf("종료합니다\n");
			break;
		default:
			printf("다시 입력하세요\n");
			break;
		}
		if (menu == 4)
			break;
	}
}
