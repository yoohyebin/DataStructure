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

void insertion(student* A, int p, int r, int gap, int a)
{
	//gap에 의애 일정한 간격으로 떨어진 요소들을 삽입정렬 해준다
	int i, j;
	student key;
	for (i = p + gap; i <= r; i += gap)
	{
		key = A[i];
		if (a == 1)
		{
			for (j = i - gap; j >= p && strcmp(key.student_id, A[j].student_id) < 0; j -= gap)
				A[j + gap] = A[j];
			A[j + gap] = key;
		}
		else if (a == 2)
		{
			for (j = i - gap; j >= p && strcmp(key.name, A[j].name) < 0; j -= gap)
				A[j + gap] = A[j];
			A[j + gap] = key;
		}
		else if (a == 3)
		{
			for (j = i - gap; j >= p && strcmp(key.department_name, A[j].department_name) < 0; j -= gap)
				A[j + gap] = A[j];
			A[j + gap] = key;
		}
		else if (a == 4)
		{
			for (j = i - gap; j >= p && key.grade < A[j].grade; j -= gap)
				A[j + gap] = A[j];
			A[j + gap] = key;
		}
		else if (a == 5)
		{
			for (j = i - gap; j >= p && strcmp(key.birthday, A[j].birthday) < 0; j -= gap)
				A[j + gap] = A[j];
			A[j + gap] = key;
		}
	}
}
void shell_sort(student* A, int n, int a)
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap /= 2) //초기 간격을 n/2로 하고 각 단계마다 간격을 반으로 줄인다
	{
		if (gap % 2 == 0) //간격이 짝수인 경우 1을 더해준다
			gap += 1;
		for (i = 0; i < gap; i++) //,일정한 간격으로 떨어진 요소를 삽입정렬 한다
			insertion(A, i, n - 1, gap, a);
	}
}

int partition(student* A, int p, int r, int a)
{
	//pivot을 선정하여 작으면 왼쪽 크면 오른쪽으로 옮겨 pivot을 제외하고 왼쪽과 오른쪽 리스트를 다시 정렬
	int low = p, high = r;
	student pivot, temp;
	pivot = A[p];
	while (low < high)
	{
		if (a == 1)
		{
			while (strcmp(pivot.student_id, A[low].student_id) >= 0 && low <= r)
				low++;
			while (strcmp(pivot.student_id, A[high].student_id) <= 0 && high >= p + 1)
				high--;
			if (low <= high)
			{
				temp = A[low];
				A[low] = A[high];
				A[high] = temp;
			}
		}
		else if (a == 2)
		{
			while (strcmp(pivot.name, A[low].name) >= 0 && low <= r)
				low++;
			while (strcmp(pivot.name, A[high].name) <= 0 && high >= p + 1)
				high--;
			if (low <= high)
			{
				temp = A[low];
				A[low] = A[high];
				A[high] = temp;
			}
		}
		else if (a == 3)
		{
			while (strcmp(pivot.department_name, A[low].department_name) >= 0 && low <= r)
				low++;
			while (strcmp(pivot.department_name, A[high].department_name) <= 0 && high >= p + 1)
				high--;
			if (low <= high)
			{
				temp = A[low];
				A[low] = A[high];
				A[high] = temp;
			}
		}
		else if (a == 4)
		{
			while (pivot.grade <= A[low].grade && low <= r)
				low++;
			while (pivot.grade <= A[high].grade && high >= p + 1)
				high--;
			if (low <= high)
			{
				temp = A[low];
				A[low] = A[high];
				A[high] = temp;
			}
		}
		else if (a == 5)
		{
			while (strcmp(pivot.birthday, A[low].birthday) >= 0 && low <= r)
				low++;
			while (strcmp(pivot.birthday, A[high].birthday) <= 0 && high >= p + 1)
				high--;
			if (low <= high)
			{
				temp = A[low];
				A[low] = A[high];
				A[high] = temp;
			}
		}
	}
	temp = A[p];
	A[p] = A[high];
	A[high] = temp;
	return high;
}
void QS(student* A, int p, int r, int a) //전체 리스트를 두 개의 부분 리스트로 분할하고 각각의 부분 리스트에 대해 재귀적으로 정렬 수행

{
	int q;
	if (p < r)
	{
		q = partition(A, p, r, a);
		QS(A, p, q - 1, a);
		QS(A, q + 1, r, a);
	}
}

void merge(student* A, int p, int q, int r, int a)
{
	//분할된 리스틀르 합병, 분할된 리스트의 요소를 하나씩 비교하여 더작은 요소를 병합을 위한 새로운 리스트로 옮긴다
	int i, j;
	student temp;
	for (i = p; i <= q; i++)
	{
		for (j = r; j >= q + 1; j--)
		{
			if (a == 1)
			{
				if (strcmp(A[i].student_id, A[j].student_id) > 0)
				{
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
			else if (a == 2)
			{
				if (strcmp(A[i].name, A[j].name) > 0)
				{
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
			else if (a == 3)
			{
				if (strcmp(A[i].department_name, A[j].department_name) > 0)
				{
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
			else if (a == 4)
			{
				if (A[i].grade > A[j].grade)
				{
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
			else if (a == 5)
			{
				if (strcmp(A[i].birthday, A[j].birthday) > 0)
				{
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
		}
	}
}
void mergeSort(student* A, int p, int r, int a)
{
	//주어진 리스트를 두개로 분할하고 분할된 리스트에 대해 재귀적으로 호출한다
	int q, i;
	if (p < r)
	{
		q = (p + r) / 2;
		mergeSort(A, p, q, a);
		mergeSort(A, q + 1, r, a);
		merge(A, p, q, r, a);
	}
}

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
			fscanf(fp, "%s %c %s %c %s %s\n", st[i - 1].student_id, &st[i - 1].department_id, st[i - 1].department_name, &st[i - 1].grade, st[i - 1].name, st[i - 1].birthday);
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
			printf("합병\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			mergeSort(st, 0, c - 1, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[merge Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("퀵\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			QS(st, 0, c - 1, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[quick Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("쉘\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			shell_sort(st, c, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[shell Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			break;
		case 2: //성명
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
			printf("합병\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			mergeSort(st, 0, c - 1, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[merge Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("퀵\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			QS(st, 0, c - 1, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[quick Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("쉘\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			shell_sort(st, c, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[shell Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			break;
		case 3: //학과
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
			printf("합병\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			mergeSort(st, 0, c - 1, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[merge Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("퀵\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			QS(st, 0, c - 1, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[quick Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("쉘\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			shell_sort(st, c, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[shell Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			break;
		case 4: //학년
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
			printf("합병\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			mergeSort(st, 0, c - 1, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[merge Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("퀵\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			QS(st, 0, c - 1, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[quick Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("쉘\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			shell_sort(st, c, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[shell Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			break;
		case 5: //생년월일
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
			printf("합병\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			mergeSort(st, 0, c - 1, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[merge Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("퀵\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			QS(st, 0, c - 1, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[quick Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
			printf("쉘\n");
			ftime(&prev);
			pt = *localtime(&prev.time);
			shell_sort(st, c, m);
			for (i = 0; i < c; i++)
				printf("%s %c %s %c %s %s\n", st[i].student_id, st[i].department_id, st[i].department_name, st[i].grade, st[i].name, st[i].birthday);
			ftime(&next);
			nt = *localtime(&next.time);
			printf("[shell Sort 수행 시간:%d:%d.%d]\n", (nt.tm_min) - (pt.tm_min), (nt.tm_sec) - (pt.tm_sec), next.millitm - prev.millitm);
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
