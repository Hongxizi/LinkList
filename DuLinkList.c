#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* pre;
	int data;
	struct Node* next;
}Node;

//获取一个整数
unsigned int GetRight()
{
	int ret;
	unsigned int i;
	ret = scanf_s("%d", &i);		//检查非法输入 
	while (ret != 1)
	{
		while (getchar() != '\n');
		printf("输入错误，请重新输入\n");
		ret = scanf_s("%d", &i);
	}
	while (getchar() != '\n');
	return i;
}

//链表初始化
Node* DuLinkListInit(int n)
{
	Node* Head ;
	do
	{
		Head = (Node*)malloc(sizeof(Node));
	} while (Head == NULL);
	Node* p = Head;
	Node* temp;	
	int i = 1;
	while (n--)
	{
		temp = (Node*)malloc(sizeof(Node));
		printf("请输入第%d个结点的数据：",i++);
		temp->data = GetRight();
		p->next = temp;
		temp->pre = p;
		temp->next = NULL;
		p = temp;			
	}
	return Head;
}

//获取链表长度
int DuLinkListLength(Node* Head)
{
	int n = 0;
	Node* p = Head;			
	while (p->next)
	{
		p = p->next;		
		n++;				
	}
	return n;
}

//插入一个结点到第n个结点后面
void DuLinkListInsert(Node* Head, int num, int n)
{
	Node* temp = NULL;
	Node* p = Head;	
	do
	{
		temp = (Node*)malloc(sizeof(Node));
	}
	while (temp == NULL);
	while (n--)						
	{
		p = p->next;
	}
	temp->next = p->next;
	p->next = temp;
	temp->pre = p;
	if(temp->next)
		temp->next->pre = temp;
	temp->data = num;
}

//输出整个链表
void DuLinkListPrintf(Node* Head)
{
	Node* p = Head->next;			
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;				
	}
	printf("NULL\n");
}

//删除第n个结点
int  DuLinkListDel(Node* Head, int n)
{
	Node* p = Head;
	int e = 0;
	while (n--)
	{
		p = p->next;
	}
	e = p->data;
	if (p->next == NULL)
	{
		p->pre->next = NULL;
	}
	else
	{
	p->pre->next = p->next;
	p->next->pre = p->pre;
	}
	free(p);
	return e;
}

//删除整个链表
void DuLinkListDestroy(Node* Head)
{
	Node* p = Head;
	while (p->next != NULL)
	{
		p = p->next;
		free(p->pre);
	}
}

//输出菜单
void Menu()
{
	printf("*************************系统功能菜单*************************\n");
	printf("--------------------------------------------------------------\n");
	printf("\t*  1.创建新链表       * *    2.插入新结点     *\n");
	printf("\t***********************************************\n");
	printf("\t*  3.输出链表         * *    4.删除节点取值   *\n");
	printf("\t***********************************************\n");
	printf("\t*              0.删除链表并退出系统           *\n");
	printf("\t***********************************************\n");
	printf("--------------------------------------------------------------\n");
	printf("请选择菜单编号:\n");
}

int main()
{
	unsigned int i = 0;
	int n = 0;
	Node* Head = NULL;
	while (1)
	{
		system("cls");
		Menu();
		i = GetRight();
		while (i > 4)
		{
			printf("输入错误，请输入0到4的指令\n");
			i = GetRight();
		}
		if ((i != 1) && (Head == NULL))
		{
			while (i != 1)
			{
				printf("当前无链表存在，请输入1新建链表\n");
				i = GetRight();
			}
		}
		switch (i)
		{
		case 1:
			printf("请输入你要构建的结点个数\n");
			Head = DuLinkListInit(GetRight());
			printf("链表初始化完成\n");
			break;
		case 2:
			printf("请问你要插入到第n个后面：\n");
			n = GetRight();
			while (n > DuLinkListLength(Head))
			{
				printf("链表没这么长，请重新输入：\n");
				n = GetRight();
			}
			printf("请输入你要插入的整数：\n");
			DuLinkListInsert(Head, GetRight(), n);
			break;
		case 3 :
			printf("链表数据依次为：\n");
			DuLinkListPrintf(Head);
			break;
		case 4 :
			printf("请问你要删除第n结点：\n");
			n = GetRight();
			while (n > DuLinkListLength(Head))
			{	
				printf("链表没这么长，请重新输入：\n");
				n = GetRight();
			}	
			printf("你删除的值是%d\n", DuLinkListDel(Head, n));
			break;
		case 0 :
			DuLinkListDestroy(Head);
			return 0;
			break;
		}
		printf("按回车返回\n");
		while (getchar() != '\n');
	}
	return 0;
}


