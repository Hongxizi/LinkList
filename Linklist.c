#include<stdio.h>
#include<stdlib.h>

//�����������ͣ�����Ϊ Node
typedef struct Node				
{
	int data;
	struct Node* next;				//ָ�������������͵�ָ��
}Node;

//�����ʼ������һ��������������n�������������ͷ����ָ��
Node* LinkListInit(int n)
{
	Node* Head;								//ͷ����ָ��	
	Head = (Node*)malloc(sizeof(Node));		//���ٶ�̬����������СΪһ���ṹ�壬��ת��Ϊ��Ӧ��ָ������
	Head->next = NULL;
	//β�巨
	Node* p = Head;							//ָ��������ָ��
	Node* temp;								//����Ľ���ָ��
	while (n--)
	{
		temp = (Node*)malloc(sizeof(Node));	

		temp->data = n;

		p->next = temp;
		temp->next = NULL;
		p = temp;				//ָ��p������
	}
	return Head;
}

//����һ����㵽��n������
void LinkListInsert(Node* Head,int num,int n)
{
	Node* temp = (Node*)malloc(sizeof(Node));		//Ҫ����Ľ���ָ��
	Node* p = Head;					//����ָ��
	while (n--)						//������n-1��
	{
		p = p->next;
	}
	temp->next = p->next;
	p->next = temp;

	temp->data = num;
}

//ɾ����n�����,��������ֵ
int LinkListDel(Node* Head, int n)
{
	int i;					//�����ӷ���ֵ
	Node* p = Head, * temp;		//��������Ҫɾ������ָ��
	while (--n)					//������n-1��
	{
		p = p->next;
	}
	temp = p->next;
	p->next = temp->next;
	i = temp->data;
	free(temp);					//�ͷſռ�
	return i;
}

//�����������
void LinkListPrintf(Node* Head)
{	
	Node* p = Head->next;			//����ָ��
	while (p != NULL)
	{
		//printf("%p	", p->next);
		printf("%d->",p->data);
		p = p->next;				//ָ�����
	}
	printf("NULL\n");
}

//��ȡ�����ȣ�������ͷ��㣩
int LinkListLength(Node* Head)
{
	int n=0;
	Node* p = Head;			//����ָ��
	while (p->next)
	{
		p = p->next;		//ָ�����
		n++;				//������1
	}
	return n;
}

//����ת
void LinkListReverse(Node* Head)
{
	Node* prenode, * midnode, * nextnode;		//����ʱ������������ָ��p,m,n
	if ((prenode = Head->next) == NULL)			//pָ���׽�㣬�ж��Ƿ�Ϊ��
		printf("������Ϊ������\n");				//��Ϊ������ʾ
	else
	{
		if ((midnode = prenode->next) == NULL);		//mָ��ڶ�����㣬�ж��Ƿ�Ϊ�գ���Ϊ�����������
		else
		{
			if ((nextnode = midnode->next) == NULL)		//nָ��������ڵ㣬�ж��Ƿ�Ϊ�գ���Ϊ����ֱ�Ӳ���
			{
				midnode->next = prenode;		//�򵥷�ת
				Head->next = midnode;
				prenode->next = NULL;
			}
			else
			{
				while (nextnode->next)			//�����м䲿�֣�����ָ��һ����ƣ�ֱ��nָ��Ľ��ָ����Ϊ��
				{
					midnode->next = prenode;	//��ת�м�ָ�뷽��
					prenode = midnode;			//ָ�����
					midnode = nextnode;
					nextnode = nextnode->next;
				}
				midnode->next = prenode;		//��ת�����ڶ������ָ����ָ�뷽��
				nextnode->next = midnode;		//��ת������һ�����ָ����ָ�뷽��
				Head->next->next = NULL;		//ԭ�׽��ָ����ָ��ָ��NULL
				Head->next = nextnode;			//ͷָ��ָ��ԭ�����
			}

		}

	}

}

//�ж��Ƿ�ɻ�
void LinkListCircularStatus(Node* Head)
{
	char flag = 0;						//���ñ�־λ��0Ϊ���ɻ���1Ϊ�ɻ�
	if (Head->next)						//�ж��Ƿ�Ϊ������
	{
		Node* p = Head->next;			//�����ָ�룬���׽�㿪ʼ
		Node* q = Head->next;			//������ָ�룬���׽�㿪ʼ
		do
		{
			p = p->next->next;			//��ָ��һ���ƶ��������
			if (p == q || p == q->next)			//�ж���ָ���Ƿ��ص� ���� ��ָ���Ѿ�������ָ��
			{
				flag = 1;
				break;							//����ѭ��
			}
			q = q->next;				//��ָ��һ���ƶ�һ�����
		} while(p && p->next);			//��ָ����ָ��ָ����ָ����ָ��ָ��NULL������ѭ��

		if (flag)						//�жϱ�־λ
			printf("����ɻ�\n");
		else
			printf("�����ɻ�\n");
	}
	else
		printf("������Ϊ������\n");
	


}

//����ɻ�
void LinkListCircular(Node* Head)
{
	Node* p = Head->next;
	if (p)
	{
		while (p->next)
			p = p->next;
		p->next = Head;								//β���ָ����ָ��ָ��ͷ���
		printf("ѭ��������ɹ�\n");
	}
	else
	{
		printf("������Ϊ�������޷�����ɻ�\n");
	}
}

//��ȡ�е�
void LinkListGetMid(Node* Head)
{
	if (Head->next)						//�ж��Ƿ�Ϊ������
	{
		Node* p = Head->next;			//�����ָ�룬���׽�㿪ʼ
		Node* q = Head->next;			//������ָ�룬���׽�㿪ʼ
		while (p->next && p->next->next)
		{
			p = p->next->next;			//��ָ��һ���ƶ��������
			q = q->next;				//��ָ��һ���ƶ�һ�����
		} 			//��ָ����ָ��ָ����ָ����ָ��ָ��NULL������ѭ��
		if(p->next)
			printf("�����Ϊż�����е�ֵΪ%d��%d\n", q->data, q->next->data);
		else
			printf("�����Ϊ�������е�ֵΪ%d\n",q->data);
	}
	else
		printf("������Ϊ������\n");
}

//��ż�Ի�
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
			p = p->next->next;					//p�����������
		}
		printf("��ż�Ի��ɹ�\n");
	}
	else
	{
		printf("������Ϊ�������޷���ż�Ի�\n");
	}
		
}

//ɾ�������˳�ϵͳ
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
	printf("�����Ѵݻ�\n");
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

//����˵�
void Menu()
{
	printf("*************************ϵͳ���ܲ˵�*************************\n");
	printf("--------------------------------------------------------------\n");
	printf("\t*  1.����������       * *    2.�����½ڵ�     *\n");
	printf("\t***********************************************\n");
	printf("\t*  3.�������         * *    4.��������     *\n");
	printf("\t***********************************************\n");
	printf("\t*  5.�ҵ��������е�   * *    6.�ж��Ƿ�ɻ�   *\n");
	printf("\t***********************************************\n");
	printf("\t*  7.ɾ���ڵ�ȡֵ     * *    8.��ż��ת       *\n");
	printf("\t***********************************************\n");
	printf("\t*               9.����ѭ������                *\n");
	printf("\t***********************************************\n");
	printf("\t*              0.ɾ�������˳�ϵͳ           *\n");
	printf("\t***********************************************\n");
	printf("--------------------------------------------------------------\n");
	printf("��ѡ��˵����:\n");
}

//���벢���Ƿ��ַ�
unsigned int GetRight()
{
	int ret;
	unsigned int i;
	ret = scanf_s("%d", &i);		//���Ƿ����� 
	while (ret != 1)
	{
		while (getchar() != '\n');
		printf("�����������������\n");
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

	//printf("\n��ǰ��������ڣ����½�һ������,�����޷����и��ֲ���\n");
	//printf("������Ҫ����������㣺");
	//Node* Head = LinkListInit(GetRight());


	while (1)
	{
		system("cls");
		Menu();
		i = GetRight();
		while (i > 9)
		{
			printf("�����������������\n");
			i = GetRight();
		}
		if ((i != 1) && (Head == NULL))
		{
			printf("��ǰ��������ڣ�������1�½�����\n");
			i = GetRight();
			while(i != 1)
			{
				printf("������1\n");
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
				printf("������Ҫ����������㣺");
				Head = LinkListInit(GetRight());
				break;
			case 2 :
				printf("������Ҫ������λ�ã���n�����棩��\n");
				int n = GetRight();
				while(n > LinkListLength(Head))
				{
					printf("����û��ô�������������룺\n");
					n = GetRight();
				}
				printf("������Ҫ����������ݣ���������\n");
				LinkListInsert(Head,GetRight(),n);
				break;
			case 3 :
				printf("������������Ϊ��\n");
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
				printf("��������Ҫɾ���ڼ������");
				printf("ɾ����ֵΪ%d\n", LinkListDel(Head,i = GetRight()));
				break;
			case 8 :
				LinkListReverseEven(Head);
				printf("����ת�ɹ�\n");
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
				printf("�����ѳɻ����޷�ִ�д˲���,ֻ������6��0\n");
				break;
		}
		getchar();
		printf("���س�����\n");
		getchar();
	}
	
	return 0;
}
