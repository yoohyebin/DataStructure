#include <stdio.h>
#include<time.h>
#include <sys/timeb.h>

typedef struct Student //student 구조체 생성 
{
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];
}student;
void selection_sorft(student* st, int n, int a) //필드번호를 함께 전송받아 필드별로 비교한다
{
	int i, j, least;
	student temp;
	//완전히 정렬될때 까지 가장작은값을 택해서 왼쪽으로 옮긴다
	for (i = n - 1; i >= 0; i--)
	{
		least = i;
		for (j = 0; j < i + 1; j++)
		{
			if (a == 1)
			{
				if (strcmp(st[j].student_id, st[least].student_id) > 0)
				{
					least = j;
				}
			}
			else if (a == 2)
			{
				if (strcmp(st[j].name, st[least].name) > 0)
				{
					least = j;
				}
			}
			else if (a == 3)
			{
				if (strcmp(st[j].department_name, st[least].department_name) > 0)
				{
					least = j;
				}

			}
			else if (a == 4)
			{
				if (st[j].grade > st[least].grade)
				{
					least = j;
				}
			}
			else if (a == 5)
			{
				if (strcmp(st[j].birthday, st[least].birthday) > 0)
				{
					least = j;
				}
			}
		}
		temp = st[i];
		st[i] = st[least];
		st[least] = temp;
	}
	for (i = 0; i < n; i++)
		printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
}
void insertion_sort(student* st, int n, int a)
{
	int i, j;
	student key;
	//두번째 부터 앞의 값과 비교해 앞보다 작으면 앞의 앞에 삽입한다
	for (i = 0; i < n; i++)
	{
		key = st[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (a == 1)
			{
				if (strcmp(key.student_id, st[j].student_id) < 0)
					st[j + 1] = st[j];
				else break;
			}
			else if (a == 2)
			{
				if (strcmp(key.name, st[j].name) < 0)
					st[j + 1] = st[j];
				else break;
			}
			else if (a == 3)
			{
				if (strcmp(key.department_name, st[j].department_name) < 0)
					st[j + 1] = st[j];
				else break;
			}
			else if (a == 4)
			{
				if (key.grade < st[j].grade)
					st[j + 1] = st[j];
				else break;
			}
			else if (a == 5)
			{
				if (strcmp(key.birthday, st[j].birthday) < 0)
					st[j + 1] = st[j];
				else break;
			}
		}
		st[j + 1] = key;
	}
	for (i = 0; i < n; i++)
		printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
}
void bubble_sort(student* st, int n, int a)
{
	int i, j;
	student temp;
	//왼쪽 끝에서부터 오른쪽으로 이동하며 비교하여 비교한 값보다 크면 둘의 위치를 바꾼다
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (a == 1)
			{
				if (strcmp(st[j].student_id, st[j + 1].student_id) > 0)
				{
					//swap
					temp = st[j];
					st[j] = st[j + 1];
					st[j + 1] = temp;
				}
			}
			else if (a == 2)
			{
				if (strcmp(st[j].name, st[j + 1].name) > 0)
				{
					temp = st[j];
					st[j] = st[j + 1];
					st[j + 1] = temp;
				}
			}
			else if (a == 3)
			{
				if (strcmp(st[j].department_name, st[j + 1].department_name) > 0)
				{
					temp = st[j];
					st[j] = st[j + 1];
					st[j + 1] = temp;
				}
			}
			else if (a == 4)
			{
				if (st[j].grade > st[j + 1].grade)
				{
					temp = st[j];
					st[j] = st[j + 1];
					st[j + 1] = temp;
				}
			}
			else if (a == 5)
			{
				if (strcmp(st[j].birthday, st[j + 1].birthday) > 0)
				{
					temp = st[j];
					st[j] = st[j + 1];
					st[j + 1] = temp;
				}
			}
		}
	}
	//출력
	for (i = 0; i < n; i++)
		printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
}
int main()
{
	char len[256];
	int c = 0, i = 0, m;
	struct timeb prev, next; //timeb구조체
	struct tm pt, nt;
	FILE* fp = fopen("students_10.txt", "rt");
	while (!feof(fp)) //파일을 읽어 학생수 찾아냄 
	{
		fgets(len, 256, fp);
		c++;
	}
	c = c - 2; //맨첫줄과 마지막 쓰레기값을 빼준다
	rewind(fp); //파일의 처음으로 올려준다
	student* st = (student*)malloc(sizeof(student) * c); //구조체를 동적할당 한다 
	while (!feof(fp))
	{
		if (i == 0) //첫번째 줄을 버린다
			fgets(len, 256, fp);
		else
			//파일을 읽어 필드별로 student 구조체에 저장한다
		i++;
	}
	while (1)
	{
		printf(">정렬하고자 하는 기준 필드를 선택하세요. (1:학번 2:성명 3:학과 4:학년 5:생년월일 6:종료)\n-->");
		scanf("%d", &m);

		switch (m)
		{
		case  1: //학번
			printf("선택\n");
			ftime(&prev); //ftime함수를 통해 현재시간을 받아옴
			pt = *localtime(&prev.time); //받아온 현재시간을 localtime형태로 변환
			selection_sorft(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			//localtime형태로 바꾼 끝난시간에서 시작시간을빼서 수행시간을 출력한다
			printf("[Selection Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("삽입\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			insertion_sort(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Insertion Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("버블\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			bubble_sort(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Bubble Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			break;
		case 2: //성명
			printf("선택\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			selection_sorft(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Selection Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("삽입\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			insertion_sort(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Insertion Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("버블\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			bubble_sort(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Bubble Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			break;
		case 3: //학과
			printf("선택\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			selection_sorft(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Selection Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("삽입\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			insertion_sort(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Insertion Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("버블\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			bubble_sort(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Bubble Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			break;
		case 4: //학년
			printf("선택\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			selection_sorft(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Selection Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("삽입\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			insertion_sort(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Insertion Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("버블\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			bubble_sort(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Bubble Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			break;
		case 5: //생년월일
			printf("선택\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			selection_sorft(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Selection Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("삽입\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			insertion_sort(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Insertion Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("버블\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			bubble_sort(st, c, m);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[Bubble Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			break;
		case 6: //종료
			printf("프로그램을 종료합니다\n");
			return;
		default:
			printf("잘못 입력하셨습니다. 다시 입력하세요\n");
			break;
		}
	}
}
