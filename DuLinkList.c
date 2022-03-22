#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* pre;
	int data;
	struct Node* next;
}Node;

//��ȡһ������
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
	while (getchar() != '\n');
	return i;
}

//�����ʼ��
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
		printf("�������%d���������ݣ�",i++);
		temp->data = GetRight();
		p->next = temp;
		temp->pre = p;
		temp->next = NULL;
		p = temp;			
	}
	return Head;
}

//��ȡ������
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

//����һ����㵽��n��������
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

//�����������
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

//ɾ����n�����
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

//ɾ����������
void DuLinkListDestroy(Node* Head)
{
	Node* p = Head;
	while (p->next != NULL)
	{
		p = p->next;
		free(p->pre);
	}
}

//����˵�
void Menu()
{
	printf("*************************ϵͳ���ܲ˵�*************************\n");
	printf("--------------------------------------------------------------\n");
	printf("\t*  1.����������       * *    2.�����½��     *\n");
	printf("\t***********************************************\n");
	printf("\t*  3.�������         * *    4.ɾ���ڵ�ȡֵ   *\n");
	printf("\t***********************************************\n");
	printf("\t*              0.ɾ�������˳�ϵͳ           *\n");
	printf("\t***********************************************\n");
	printf("--------------------------------------------------------------\n");
	printf("��ѡ��˵����:\n");
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
			printf("�������������0��4��ָ��\n");
			i = GetRight();
		}
		if ((i != 1) && (Head == NULL))
		{
			while (i != 1)
			{
				printf("��ǰ��������ڣ�������1�½�����\n");
				i = GetRight();
			}
		}
		switch (i)
		{
		case 1:
			printf("��������Ҫ�����Ľ�����\n");
			Head = DuLinkListInit(GetRight());
			printf("�����ʼ�����\n");
			break;
		case 2:
			printf("������Ҫ���뵽��n�����棺\n");
			n = GetRight();
			while (n > DuLinkListLength(Head))
			{
				printf("����û��ô�������������룺\n");
				n = GetRight();
			}
			printf("��������Ҫ�����������\n");
			DuLinkListInsert(Head, GetRight(), n);
			break;
		case 3 :
			printf("������������Ϊ��\n");
			DuLinkListPrintf(Head);
			break;
		case 4 :
			printf("������Ҫɾ����n��㣺\n");
			n = GetRight();
			while (n > DuLinkListLength(Head))
			{	
				printf("����û��ô�������������룺\n");
				n = GetRight();
			}	
			printf("��ɾ����ֵ��%d\n", DuLinkListDel(Head, n));
			break;
		case 0 :
			DuLinkListDestroy(Head);
			return 0;
			break;
		}
		printf("���س�����\n");
		while (getchar() != '\n');
	}
	return 0;
}


