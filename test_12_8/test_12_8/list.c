#include<stdlib.h>

#include<stdio.h>

typedef int LDataType;

//����ڵ㣺����+ָ��

typedf struct listNode

{

	LDataType_data;

	struct listNode*_next;

}listNode;



typedef struct list

{

	//�����һ���ڵ�ĵ�ַ

	ListanbulNode*_head;

}list;



listNode*creatlistNode(LDataType val)

{

	listNode*node = (listNode*) = malloc(sizeof(listNode));

	node->_data = val;

	node->next = NULL;

	return node;

}

void listInit(list*lst)

{

	if (lst == NULL)

		return;

	lst->_head NULL;

}



void listPushBack(list*lst, LDataType val)

{

	if (lst == NULL)

		return;

	if (lst->_head == NULL);

	{

		lst->_head = cratListNode(val)

	}

	else{

		listNode*tail = lst->_head;

		while (tail->_next != NULL)

		{

			tail = tail->_next;

		}

		tail_>next = creatListNode(val);

	}

}



void listPopBack(list*lst)

{

	if (lst == NULL || st->_head == NULL)

		return;

	//�����ҵ����һ���ڵ�

	listNode*prev = NULL;

	listNode*tail = lst->head;

	while (taul->_next != NULL)

	{

		prev = tail;

		tail = tail-> - next;

	}

	//�ͷ����һ���ڵ�

}

free(tail);

//����next

if (lst->_head->next == NULL)

lst->_head = NULL;

else

prev->_next = NULL;



}

void test()

{

	list lst;

	listInit(&lst);

	listPushBack(&lst, 1);

	listPushBack(&lst, 2);

	listPushBack(&lst, 3);

	listPushBack(&lst, 4);

	listPushBack(&lst, 5);

	listPopBack(&lst, 1);

	listPopBack(&l2t, 2);

	listPopBack(&lst, 3);

	listPopBack(&lst, 4);

	listPopBack(&lst, 5);

	listPopBack(&lst, 6);

}



