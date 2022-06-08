#include "calculator.h"

LinkedStack* calculator; //linkedstack 구조체 선언 
int count = 0;

void init_stack() {
	calculator = (LinkedStack*)malloc(sizeof(LinkedStack)); //구조체 동적할당 
	calculator->top = NULL; //calculator의 top을 NULL로 초기화 
}

int is_empty()
{
	return calculator->top = NULL; //calculator의 top을 NULL로 초기화 
}

int push(StackNode* new_node) //stack에 node 추가 
{
	if (calculator->top == NULL) //stack에 노드가 하나도 없을때 
	{
		calculator->top = new_node; //calculator의 top이 new-node를 가르키도록 한다. 
		new_node->link = NULL; //new_node의 link를 null로 초기화  
	}
	else //stack에 node가 있었을 경우 
	{
		new_node->link = calculator->top; //new_node의 link는 calculator의 top을 가르키도록 한다. 
		calculator->top = new_node; //calculator의 top은 new_node를 가르키도록 한다. 
	}
	count++; //stack에 들어가는 node의 개수를 센다. 
}

StackNode* pop() //stack에 있는 node를 제거 
{
	StackNode* node; //새로운 node생성 
	if (calculator->top == NULL) //stack이 비어있을때 
	{
		return NULL;
	}
	else
	{
		node = calculator->top;  //node에 calculator의 top 대입 
		calculator->top = calculator->top->link; //calculator의 top에 calculator의 top 이가르키고 있는 node의 link 대입 
		return node;
	}
}

int main()
{
	int len, i, j = 0, k = 0, c = 0, b = 0, p = 0;
	char input[200];
	//pop에서 반환받기 위해 구조체 선언 
	StackNode* n1 = NULL;
	StackNode* n2 = NULL;
	StackNode* n3 = NULL;
	StackNode* n= NULL;
	init_stack(); //calculator 구조체 동적할당과 초기화를 위해 함수를 호출
	printf("--->");
	gets(input);
	len = strlen(input); //입력받은 배열의 길이를 측정 
	for (i = 0; i < len; i++) //배열의 길이 만큼
	{
		if (i == len - 1) //배역의 마지막일때 
		{
			StackNode* newnode = (StackNode*)malloc(sizeof(StackNode));
			newnode->item.operand = (atoi)(&input[j]);
			push(newnode);
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') //연산자 일때
		{
			StackNode* newnode = (StackNode*)malloc(sizeof(StackNode));//새로운node생성 
			newnode->item.operand = (atoi)(&input[j]); //입력받은 숫자를 형변환 해서 대입 
			j = i + 1; //형변환시 숫자의 시작을 알려주기 위해서 
			if (input[i] == '*')
			{
				k = (atoi)(&input[j]); //*연산자 다음의 숫자를 형변환 
				if (input[b] == '*' || input[b] == '/')//이 전의 연산자도 * 혹은 / 였다면 
				{
					n = pop(); //pop을 통해 그전의 숫자 불러옴 
					newnode->item.operand = n->item.operand * k; //그전의 숫자와 현재 입력한 숫자를 연산 
					b++; //연산자수 
				}
				else
				{
					newnode->item.operand *= k; //*앞의 숫자와 곱한다
					b++;
				}
				while (k) // *뒤의 숫자의 길이를 찾기위함
				{
					k /= 10;
					c++;
				}
				i += (c + 1); //숫자의 길이만큼 i값증가
			}
			else if (input[i] == '/')
			{

				k = (atoi)(&input[j]); // /연산자 다음의 숫자를 형변환
				if (input[b] == '*' || input[b] == '/')
				{
					n = pop();//pop을 통해 그전의 숫자 불러옴
					newnode->item.operand = n->item.operand / k; //그전의 숫자와 현재 입력한 숫자를 연산
					b++;
				}
				else
				{
					newnode->item.operand /= k; // /앞의 숫자와 곱한다
					b++;
				}
				while (k) // /뒤의 숫자의 길이를 찾기위함
				{
					k /= 10;
					c++;
				}
				i += (c + 1);//숫자의 길이만큼 i값증가
			}
			push(newnode); //push함수를 호출해 stack에 추가 
			if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') //연산을 끝낸후 그 뒤또한 연산자 라면 혹은 현재 연산자 라면 
			{
				StackNode* new_node = (StackNode*)malloc(sizeof(StackNode)); //새로운 node생성 
				new_node->item.operator=input[i];//연산자 대입 
				push(new_node); //push함수를 호출해 stack에 추가 
				j = i + 1;
				b++;
			}
		}
	}
	for (i = 0; i < count; i = i + 3) //3개씩 호출하기 때문에 i를 3씩 증가 
	{
		//pop함수 호출해 stack의 위 
		n1 = pop();
		n2 = pop();
		n3 = pop();
		if (n2 == NULL) //연산이 다 끝나면 
			break;
		StackNode* new_node = (StackNode*)malloc(sizeof(StackNode)); //새로운 node생성 
		if (n2->item.operator=='+')
			new_node->item.operand = n1->item.operand + n3->item.operand; //새로운 node에 둘의 연산값을 대입 
		else if (n2->item.operator=='-')
		{
			if (p != 0) //p가 0이아니라는 것은 이미 한변 연산을 한 결과값과 다시 연산할때 
				new_node->item.operand = n1->item.operand - n3->item.operand; //새로운 node에 둘의 연산값을 대입 
			else
				new_node->item.operand = n3->item.operand - n1->item.operand; //새로운 node에 둘의 연산값을 대입 
		}
		push(new_node); //연산결과를 stack에 추가 
		p++;
	}
	printf("%d\n", n1->item.operand); //결과값 출력 
}
