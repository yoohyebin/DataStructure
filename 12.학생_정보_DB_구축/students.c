#include <stdio.h>
typedef struct Student //student 구조체 생성 
{
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];
	unsigned int key;
	unsigned int slot;
	struct _Student* next;
}student;

void insert(student** phead, student* newnode)
{
	student* p = NULL;
	if ((*phead)->slot == 0)	//연결리스트에 아무 내용이 없을때
	{
		(*phead) = newnode;
		newnode->next = NULL;
		(*phead)->slot = 0; //slot을 0으로 초기화
	}
	else
	{
		for (p = *phead; p->next != NULL; p = p->next); //p가 마지막 노드
		p->next = newnode; //마지막 노드에 새로운 노드를 연결한다
		newnode->next = NULL; //연결한 노드의 다음을 null로 초기화
	}
	(*phead)->slot++;
}
int main()
{
	int c = 0, i = 0, b, l, j, key = 0, a = 0;
	char len[256], name[30];
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
	printf(">생성할 해시 테이블의 버킷 수를 입력하시오: ");
	scanf("%d", &b);
	student* bucket[100];
	student* curr = NULL;
	for (i = 0; i < b; i++)
	{
		bucket[b]->slot = 0;
	}
	for (i = 0; i < c; i++)
	{
		//이름의 길이를 구해 길이 만큼 각 자리를 더해 255와 &연산 해주고 버킷의 갯수로 나누어 준다
		l = 0;
		st[i].key = 0;
		l = strlen(st[i].name);
		for (j = 0; j < l; j++)
		{
			st[i].key += st[i].name[j];
		}
		st[i].key = st[i].key & 255;
		j = st[i].key % b;
		insert(&bucket[j], &st[i]);
	}
	for (i = 0; i < b; i++)
	{
		if (bucket[i] == NULL) //노드가 null이면 연결된 slot이 하나도 없다는 것이기때문에 0 출력
			printf("Bucket[%d] - Slot 0\n", i);
		else
			printf("Bucket[%d] - Slot %d\n", i, bucket[i]->slot);
	}
	//검색하고자 하는 학생의 이름을 입력받아 key값을 구해주고 해당 버킷과 그 슬롯의 갯수를 출력한다
	printf(">검색하고자 하는 학생 이름을 입력하세요. ->");
	scanf("%s", name);
	l = strlen(name);
	for (i = 0; i < l; i++)
		key += name[i];
	key = key & 255;
	j = key % b;
	for (curr = bucket[j]; curr != NULL; curr = curr->next) //해당 버킷의 처음 부터 마지막까지 입력받은 이름과 현재 노드의 이름이 같으면 현재 노드의 데이터를 출력한다
	{
		a++;
		if (curr->key == key)
		{
			printf("Bucket[%d] - Slot %d\n", j, a);
			printf("%s	%c	%s	%c	%s	%s\n", curr->student_id, curr->department_id, curr->department_name, curr->grade, curr->name, curr->birthday);
		}
	}
}
