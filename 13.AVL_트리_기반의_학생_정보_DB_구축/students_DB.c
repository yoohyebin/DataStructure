#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX(a, b) ((a>b)? a:b)
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

treeNode* LL_rotate(treeNode* parent)//문제구간중 상위 구간을 오른쪽으로 회전 
{
	treeNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
treeNode* RR_rotate(treeNode* parent) //문제구간중 상위 구간을 왼쪽으로 회전 
{
	treeNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}
treeNode* LR_rotate(treeNode* parent) //문제구간중 하위 구간을 왼쪽으로 1차회전후 LL회전 적용 
{
	treeNode* child = parent->left;
	parent->left = RR_rotate(child);
	return LL_rotate(parent);
}
treeNode* RL_rotate(treeNode* parent) //문제구간중 하위 구간을 오른쪽으로 1차회전후 RR회전 적용
{
	treeNode* child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}
int getHeight(treeNode* p)  //트리의 높이
{
	int height = 0;
	if (p != NULL)
		height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	return height;
}
int getBF(treeNode* p) //균형인수
{
	if (p == NULL) return 0;
	return getHeight(p->left) - getHeight(p->right);
}
treeNode* rebalance(treeNode** p) { //회전 수행
	int bf = getBF(*p); //균형인수
	if (bf > 1)
	{
		if (getBF((*p)->left) > 0)
			*p = LL_rotate(*p);
		else
			*p = LR_rotate(*p);
	}
	else if (bf < -1)
	{
		if (getBF((*p)->right) < 0)
			*p = RR_rotate(*p);
		else
			*p = RL_rotate(*p);
	}
	return *p;
}
void search(treeNode* root, treeNode* node, int i)
{
	//검색할 필드를 중위 순회구조의 재귀함수를 통해 전체 노드와 비교하여 같다면 출력한다
	if (i == 1)
	{
		if (root)
		{
			search(root->left, node, i);
			if (strcmp(root->student_id, node->student_id) == 0)
				printf("%s %c %s %c %s %s\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
			search(root->right, node, i);
		}
	}
	else if (i == 2)
	{
		if (root)
		{
			search(root->left, node, i);
			if (strcmp(root->name, node->name) == 0)
				printf("%s %c %s %c %s %s\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
			search(root->right, node, i);
		}
	}
	else if (i == 3)
	{
		if (root)
		{
			search(root->left, node, i);
			if (strcmp(root->department_name, node->department_name) == 0)
				printf("%s %c %s %c %s %s\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
			search(root->right, node, i);
		}
	}
	else if (i == 4)
	{
		if (root)
		{
			search(root->left, node, i);
			if (root->grade == node->grade)
				printf("%s %c %s %c %s %s\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
			search(root->right, node, i);
		}
	}
	else if (i == 5)
	{
		if (root)
		{
			search(root->left, node, i);
			if (strcmp(root->birthday, node->birthday) == 0)
				printf("%s %c %s %c %s %s\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
			search(root->right, node, i);
		}
	}
}
treeNode* insertNode(treeNode* p, treeNode* node)
{
	if (p == NULL) //첫 노드 일때
	{
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	else if (strcmp(node->student_id, p->student_id) < 0) //노드의 학번이 루트의 학번보다 작으면 왼쪽
	{
		p->left = insertNode(p->left, node);
		rebalance(&p);
	}
	else if (strcmp(node->student_id, p->student_id) > 0) //노드의 학번이 루트의 학번보다 크면 오른쪽
	{
		p->right = insertNode(p->right, node);
		rebalance(&p);
	}
	return p;
}
void deleteNode(treeNode* root, treeNode* node)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while (strcmp(p->student_id, node->student_id) != 0) //입력한 학번과 같을때 까지
	{
		if (strcmp(p->student_id, node->student_id) > 0) //입력한 학번이 더 작다면 parent는 p가되고 p는 왼쪽으로 간다
		{
			parent = p;
			p = p->left;
		}
		else  //입력한 학번이 더 크다면 parent는 p가되고 p는 오른쪽으로 간다
		{
			parent = p;
			p = p->right;
		}
		if (p == NULL)
			break;
	}
	if (p == NULL) //삭제할 노드가 없다면
	{
		printf("%s is Not Found\n", node->student_id);
		return 0;
	}
	else if ((p->left == NULL) && (p->right == NULL)) //삭제할 노드가 단말 노드일때
	{
		if (parent != NULL) { //삭제하려는 노드가 root가 아니면
			if (parent->left == p)parent->left = NULL; //삭제하려는 노드가 왼쪽이면 왼쪽을 null로 초기화
			else parent->right = NULL; //삭제하려는 노드가 오른쪽이면 왼쪽을 null로 초기화
		}
		else root = NULL;
	}
	else if ((p->left == NULL) || (p->right == NULL)) //삭제할 노드가 자식이 한 개 일때
	{
		//삭제할 노드의 자식이 왼쪽이면 child는 p의 왼쪽 아니면 오른쪽
		if (p->left != NULL)
			child = p->left;
		else
			child = p->right;

		if (parent != NULL) //삭제하려는 노드가 root가 아니면
		{
			if (parent->left == p) //삭제하려는 노드가 왼쪽이면 왼쪽을 child와 연결
				parent->left = child;
			else parent->right = child;//삭제하려는 노드가 오른쪽이면 오른쪽을 child와 연결
		}
		else root = child;
	}
	else //삭제할 노드의 자식이 두개 일때
	{
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ)
			succ_parent->left = succ->left;
		else
			succ_parent->right = succ->left;
		p = succ;
	}
	free(p);
	printf("삭제 성공\n");
}
void displayInorder(treeNode* root)
{
	if (root) //root가 null이 될때 까지 중위 순회구조의 재귀함수를 통해 모든 node를 출력한다
	{
		displayInorder(root->left);
		printf("%s %c %s %c %s %s\n", root->student_id, root->department_id, root->department_name, root->grade, root->name, root->birthday);
		displayInorder(root->right);
	}
}
int main()
{
	treeNode* root = NULL;
	FILE* fp = fopen("students_10.txt", "rt");
	int menu, c = 0, i = 0;
	char len[256], word[50];

	while (!feof(fp)) //파일을 읽어 파일에 있는 학생수를 구함
	{
		fgets(len, 256, fp);
		c++;
	}
	rewind(fp); //파일을 첫줄로 올린다
	while (!feof(fp))
	{
		if (i == 0) //첫번째 줄은 버린다
			fgets(len, 256, fp);
		else
		{
			//새로운 노드를 생성해 노드에 학생정보를 입력한다
			treeNode* node = (treeNode*)malloc(sizeof(treeNode));
			fscanf(fp, "%s %c %s %c %s %s\n", node->student_id, &node->department_id, node->department_name, &node->grade, node->name, node->birthday);
			if (i == 1) //root를 지정하기 위해서 첫번째 노드만 반환받는다
				root = insertNode(root, node);
			else
			{
				root = insertNode(root, node);
			}
		}
		i++;
	}

	while (1)
	{
		printf(">원하는 기능을 입력하세요(1:검색 2:추가 3:삭제 4:출력 5:종료)\n");
		printf("-->");
		scanf(" %d", &menu);
		switch (menu)
		{
		case 1:
			printf(">검색할 필드명 (1:학번 2:성명 3:학과 4:학년 5:생년월일)과 검색어 입력 -->");
			scanf(" %d", &i);
			treeNode* newnode1 = (treeNode*)malloc(sizeof(treeNode)); //노드생성후 필요한 필드에 정보를 입력해서 검색하는 함수로 보낸다
			if (i == 1)
			{
				scanf(" %s", newnode1->student_id);
				search(root, newnode1, i);
			}
			else if (i == 2)
			{
				scanf(" %s", newnode1->name);
				search(root, newnode1, i);
			}
			else if (i == 3)
			{
				scanf(" %s", newnode1->department_name);
				search(root, newnode1, i);
			}
			else if (i == 4)
			{
				scanf(" %c", &newnode1->grade);
				search(root, newnode1, i);
			}
			else if (i == 5)
			{
				scanf(" %s", newnode1->birthday);
				search(root, newnode1, i);
			}
			break;
		case 2:
			printf("추가 정보 입력:");
			treeNode* newnode = (treeNode*)malloc(sizeof(treeNode)); //노드를 생성해 학생정보를 입력받고 추가 함수로 보낸다
			scanf(" %s %c %s %c %s %s", newnode->student_id, &newnode->department_id, newnode->department_name, &newnode->grade, newnode->name, newnode->birthday);
			insertNode(root, newnode);
			break;
		case 3:
			printf("삭제할 학번 입력:");
			treeNode* newnode3 = (treeNode*)malloc(sizeof(treeNode)); //노드를 생성해 학생정보를 입력받고 삭제 함수로 보낸다
			scanf(" %s", newnode3->student_id);
			deleteNode(root, newnode3);
			break;
		case 4:
			displayInorder(root); //출력함수로 보낸다
			printf("\n");
			break;
		case 5:
			printf("프로그램을 종료합니다\n");
			return 0;
		default:
			printf("잘못된 선택입니다 다시 입력하세요\n");
			break;
		}
	}
}
