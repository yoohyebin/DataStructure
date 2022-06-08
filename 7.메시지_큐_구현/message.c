#include "LinkedQueue.h"
LinkedQueue* queue; //연결리스트 구조체 선언 
int count = 0; //입력한 메시지 수를 세기위함 
//구조체 동적할당, 초기화 
void createLinkedQ() {
	queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	queue->front = NULL;
	queue->rear = NULL;
}
int isEmpty()
{
	if (queue->front == NULL) return 1;
	else return 0;
}
int enqueue(MQ_Node* newnode) //queue에 node를 추가 
{
	if (queue->front == NULL) //node가 없을때 
	{
		//queue의 처음과 마지막이 모두 새로운node를 가르키도록 함 
		queue->rear = newnode;
		queue->front = newnode;
		newnode->next == NULL;
	}
	else {
		//queue의 마지막의 next가 새로운 node를 가르키고 마지막은 새로운 node를 가르키도록 함 
		queue->rear->next = newnode;
		queue->rear = newnode;
		queue->rear->next = NULL;
	}
	count++;
}
MQ_Node* dequeue() //queue에있는 node를 버림 
{
	MQ_Node* node = queue->front; //새로운node은 queue의 첫번째 
	if (isEmpty() == 1) return NULL; //queue에 아무것도 없다면 null을 리턴한다 
	else {
		queue->front = queue->front->next; //queue의 맨 처음은 맨처은의 다음을 가르키도록 함 
		return node;
	}
}
void time_print(MQ_Node* newnode) //현재시간과 입력시간을  비교하여 입력시간이  현재시간보다 작거나 같으면 메시지 출력 
{
	while (1)
	{
		time_t t = time(NULL);

		if (t >= newnode->start_time)
		{
			printf("message:%s ,request: %d ", newnode->message, newnode->start_time);
			printf("current time: %d\n", t);
			break;
		}
	}
}
int main()
{
	char* token, a[50] = { 0 }, delim[] = "- : \n";
	int i = 0;
	struct tm t;
	MQ_Node* n;

	createLinkedQ();
	while (1)
	{
		MQ_Node* newnode = (MQ_Node*)malloc(sizeof(MQ_Node)); //node 생성
		//입력받는 메시지와 시간의 주소가 바뀔 수 있도록 동적할당 함 
		char* input_m = (char*)malloc(sizeof(char) * 100);
		char* input_t = (char*)malloc(sizeof(char) * 50);
		printf("전달할 메시지를 입력하세요(입력이 완료되면 quit 입력)--> ");
		gets(input_m);
		if (strcmp(input_m, "quit") == 0)
			break;
		printf("실행시간을 입력하세요.(형식:2018-04-18 02:18)\n-->");
		gets(input_t);
		newnode->message = input_m;

		//입력받은 시간을 token을 이용해 분리
		i = 0;
		token = strtok(input_t, delim);
		strcpy(a, token);
		t.tm_year = atoi(a) - 1900;
		while ((token = strtok(NULL, delim)) != NULL) {
			if (i == 0)
			{
				strcpy(a, token);
				t.tm_mon = atoi(a) - 1;
				i++;
			}
			else if (i == 1)
			{
				strcpy(a, token);
				t.tm_mday = atoi(a);
				i++;
			}
			else if (i == 2)
			{
				strcpy(a, token);
				t.tm_hour = atoi(a);
				i++;
			}
			else if (i == 3)
			{
				strcpy(a, token);
				t.tm_min = atoi(a);
				i++;
			}
		}
		t.tm_sec = 0;
		t.tm_isdst = 0;

		newnode->start_time = mktime(&t); //t를 time_t형으로 변환
		enqueue(newnode);
	}
	printf("메시지 입력을 완료합니다.\n");
	if (count == 0) //입력받은 것이 없을때 종료 
		return;
	else
	{
		printf("%d개의 메시지가 등록되었습니다.\n", count);
		for (i = 0; i < count; i++)
		{
			n = dequeue(); //node를 리턴 받 
			time_print(n);
		}
	}
}
