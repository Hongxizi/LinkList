#include<stdio.h>
#include<stdlib.h>

//定义数据类型，别名为 Node
typedef struct Node				
{
	int data;
	struct Node* next;				//指向这种数据类型的指针
}Node;

//链表初始化，建一个空链表，并构建n个结点数，返回头结点的指针
Node* LinkListInit(int n)
{
	Node* Head;								//头结点的指针	
	Head = (Node*)malloc(sizeof(Node));		//开辟动态储存区，大小为一个结构体，并转换为对应的指针类型
	Head->next = NULL;
	//尾插法
	Node* p = Head;							//指向最后结点的指针
	Node* temp;								//插入的结点的指针
	while (n--)
	{
		temp = (Node*)malloc(sizeof(Node));	

		temp->data = n;

		p->next = temp;
		temp->next = NULL;
		p = temp;				//指针p往后移
	}
	return Head;
}

//插入一个结点到第n个后面
void LinkListInsert(Node* Head,int num,int n)
{
	Node* temp = (Node*)malloc(sizeof(Node));		//要插入的结点的指针
	Node* p = Head;					//计数指针
	while (n--)						//计数到n-1个
	{
		p = p->next;
	}
	temp->next = p->next;
	p->next = temp;

	temp->data = num;
}

//删除第n个结点,并返回其值
int LinkListDel(Node* Head, int n)
{
	int i;					//用来接返回值
	Node* p = Head, * temp;		//计数结点和要删除结点的指针
	while (--n)					//计数到n-1个
	{
		p = p->next;
	}
	temp = p->next;
	p->next = temp->next;
	i = temp->data;
	free(temp);					//释放空间
	return i;
}

//输出整个链表
void LinkListPrintf(Node* Head)
{	
	Node* p = Head->next;			//遍历指针
	while (p != NULL)
	{
		//printf("%p	", p->next);
		printf("%d->",p->data);
		p = p->next;				//指针后移
	}
	printf("NULL\n");
}

//获取链表长度（不包括头结点）
int LinkListLength(Node* Head)
{
	int n=0;
	Node* p = Head;			//遍历指针
	while (p->next)
	{
		p = p->next;		//指针后移
		n++;				//计数加1
	}
	return n;
}

//链表反转
void LinkListReverse(Node* Head)
{
	Node* prenode, * midnode, * nextnode;		//操作时连续三个结点的指针p,m,n
	if ((prenode = Head->next) == NULL)			//p指向首结点，判断是否为空
		printf("该链表为空链表\n");				//若为空则提示
	else
	{
		if ((midnode = prenode->next) == NULL);		//m指向第二个结点，判断是否为空，若为空则无需操作
		else
		{
			if ((nextnode = midnode->next) == NULL)		//n指向第三个节点，判断是否为空，若为空则直接操作
			{
				midnode->next = prenode;		//简单反转
				Head->next = midnode;
				prenode->next = NULL;
			}
			else
			{
				while (nextnode->next)			//操作中间部分，三个指针一起后移，直到n指向的结点指针域为空
				{
					midnode->next = prenode;	//反转中间指针方向
					prenode = midnode;			//指针后移
					midnode = nextnode;
					nextnode = nextnode->next;
				}
				midnode->next = prenode;		//反转倒数第二个结点指针域指针方向
				nextnode->next = midnode;		//反转倒数第一个结点指针域指针方向
				Head->next->next = NULL;		//原首结点指针域指针指向NULL
				Head->next = nextnode;			//头指针指向原最后结点
			}

		}

	}

}

//判断是否成环
void LinkListCircularStatus(Node* Head)
{
	char flag = 0;						//设置标志位，0为不成环，1为成环
	if (Head->next)						//判断是否为空链表
	{
		Node* p = Head->next;			//定义快指针，从首结点开始
		Node* q = Head->next;			//定义慢指针，从首结点开始
		do
		{
			p = p->next->next;			//快指针一次移动两个结点
			if (p == q || p == q->next)			//判断两指针是否重叠 或者 快指针已经超过慢指针
			{
				flag = 1;
				break;							//跳出循环
			}
			q = q->next;				//慢指针一次移动一个结点
		} while(p && p->next);			//快指针或快指针指向结点指针域指针指向NULL，结束循环

		if (flag)						//判断标志位
			printf("链表成环\n");
		else
			printf("链表不成环\n");
	}
	else
		printf("该链表为空链表\n");
	


}

//构造成环
void LinkListCircular(Node* Head)
{
	Node* p = Head->next;
	if (p)
	{
		while (p->next)
			p = p->next;
		p->next = Head;								//尾结点指针域指针指向头结点
		printf("循环链表构造成功\n");
	}
	else
	{
		printf("该链表为空链表，无法构造成环\n");
	}
}

//获取中点
void LinkListGetMid(Node* Head)
{
	if (Head->next)						//判断是否为空链表
	{
		Node* p = Head->next;			//定义快指针，从首结点开始
		Node* q = Head->next;			//定义慢指针，从首结点开始
		while (p->next && p->next->next)
		{
			p = p->next->next;			//快指针一次移动两个结点
			q = q->next;				//慢指针一次移动一个结点
		} 			//快指针或快指针指向结点指针域指针指向NULL，结束循环
		if(p->next)
			printf("结点数为偶数，中点值为%d和%d\n", q->data, q->next->data);
		else
			printf("结点数为奇数，中点值为%d\n",q->data);
	}
	else
		printf("该链表为空链表\n");
}

//奇偶对换
void LinkListReverseEven(Node* Head)
{
	int tempdata;
	Node* p = Head->next;
	if (p)
	{
		while (p != NULL && p->next != NULL)
		{
			tempdata = p->data;
			p->data = p->next->data;
			p->next->data = tempdata;
			p = p->next->next;					//p后移两个结点
		}
		printf("奇偶对换成功\n");
	}
	else
	{
		printf("该链表为空链表，无法奇偶对换\n");
	}
		
}

//删除链表并退出系统
void LinkListDestroy(Node* Head)
{
	Node* p = Head;
	Node* temp;
	while (p->next)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
	free(p);
	printf("链表已摧毁\n");
}


//int main()
//{
//	Node* Head = LinkListInit(9);
//	LinkListPrintf(Head);
//	printf("Hello World!\n");
//	//LinkListInsert(Head, 3);
//	//LinkListPrintf(Head);
//	//printf("Hello World!\n");
//	//printf("%d\n",LinkListDel(Head, 3));
//	//LinkListPrintf(Head);
//	//printf("Hello World!\n");
//	//printf("%d",LinkListLength(Head));
//	//LinkListReverse(Head);
//	//LinkListPrintf(Head);
//	//printf("Hello World!\n");
//	//LinkListGetMid(Head);
//	//LinkListCircular(Head);
//	//LinkListCircularStatus(Head);
//	//LinkListReverseEven(Head);
//	//LinkListPrintf(Head);
//
//	return 0;
//}

//输出菜单
void Menu()
{
	printf("*************************系统功能菜单*************************\n");
	printf("--------------------------------------------------------------\n");
	printf("\t*  1.创建新链表       * *    2.插入新节点     *\n");
	printf("\t***********************************************\n");
	printf("\t*  3.输出链表         * *    4.将链表反向     *\n");
	printf("\t***********************************************\n");
	printf("\t*  5.找到单链表中点   * *    6.判断是否成环   *\n");
	printf("\t***********************************************\n");
	printf("\t*  7.删除节点取值     * *    8.奇偶反转       *\n");
	printf("\t***********************************************\n");
	printf("\t*               9.构造循环链表                *\n");
	printf("\t***********************************************\n");
	printf("\t*              0.删除链表并退出系统           *\n");
	printf("\t***********************************************\n");
	printf("--------------------------------------------------------------\n");
	printf("请选择菜单编号:\n");
}

//输入并检测非法字符
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
	return i;
}

int main()
{
	unsigned int i = 0;
	int flag = 0;
	Node* Head = NULL;
	Menu();

	//printf("\n当前无链表存在，请新建一个链表,否则无法进行各种操作\n");
	//printf("请问你要构建几个结点：");
	//Node* Head = LinkListInit(GetRight());


	while (1)
	{
		system("cls");
		Menu();
		i = GetRight();
		while (i > 9)
		{
			printf("输入错误，请重新输入\n");
			i = GetRight();
		}
		if ((i != 1) && (Head == NULL))
		{
			printf("当前无链表存在，请输入1新建链表\n");
			i = GetRight();
			while(i != 1)
			{
				printf("请输入1\n");
				i = GetRight();
			}
		}
		if (flag)
		{
			if (i != 6 && i != 0)
				i = 10;
		}
		switch (i)
			{
			case 1 :
				printf("请问你要构建几个结点：");
				Head = LinkListInit(GetRight());
				break;
			case 2 :
				printf("请问你要插入结点位置（第n个后面）：\n");
				int n = GetRight();
				while(n > LinkListLength(Head))
				{
					printf("数组没这么长，请重新输入：\n");
					n = GetRight();
				}
				printf("请问你要插入结点的数据（整数）：\n");
				LinkListInsert(Head,GetRight(),n);
				break;
			case 3 :
				printf("链表数据依次为：\n");
				LinkListPrintf(Head);
				break;
			case 4 :
				LinkListReverse(Head);
				break;
			case 5 :
				LinkListGetMid(Head);
				break;
			case 6 :
				LinkListCircularStatus(Head);
				break;
			case 7 :
				printf("请输入你要删除第几个结点");
				printf("删除的值为%d\n", LinkListDel(Head,i = GetRight()));
				break;
			case 8 :
				LinkListReverseEven(Head);
				printf("链表反转成功\n");
				break;
			case 9 :
				LinkListCircular(Head);
				flag = 1;
				break;
			case 0:
				LinkListDestroy(Head);
				return 0;
				break;
			case 10 :
				printf("链表已成环，无法执行此操作,只能输入6或0\n");
				break;
		}
		getchar();
		printf("按回车返回\n");
		getchar();
	}
	
	return 0;
}
