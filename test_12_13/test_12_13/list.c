//
//
//
//struct ListNode*prev, *cur;
//cur = head;
//prev = NULL;
//while (cur)
//{
//	if (cur->val == val)
//	{
//		struct ListNode*next = cur cur->next;
//		//�ͷ�
//		free(cur);
//		//��������
//		if (prev == NULL)
//			head = next;
//		else
//			prev->next = next;
//	}
//	prev = cur;
//	cur=cur->next
//	}
//return head;
//}
//struct ListNode*  reverseList(struct ListNode*head)
//	{
//		struct ListNode*newHead, *cur, *next;
//		newHead = NULL;
//		cur = head;
//		while (cur)
//		{
//			next = cur->next;
//			cur->next = newHead;
//	newHead = cur;
//}
//	}
//return newHead;
//
//n1,n2,n3
//struct ListNode*  middleNode(struct ListNode*head)	 //һ�α����ҵ��м�ڵ㣬����ͷ�ڵ㣬һ����һ����һ��������
//{
//	struct ListNode*fast, *slow;
//	fast = head;
//	slow = head;
//	while (fast&&fast->next)
//	{
//		fast  = fast->next->next;
//		slow = slow->next;
//	}
//	return slow;
//}
//struct ListNode*  mergeTwoList(struct ListNode * l1, struct ListNode * l2)
//{
//
//}
#include<stdio.h>
struct ListNode*fast = head, *slow = head;
while (fast&&fast->next)
{
	fast = fast->next->next;
	slow = slow->next;
}
return slow;
struct ListNode*newHead, *next;
		newHead = NULL;
		slow = head;
		while (slow)
		{
			next = slow->next;
			slwo->next = newHead;
			newHead = slow;
		}


start1 = head;
start2 = newhead;

while (start2&&start1)
{
	if (start1 == start2)
	{
		start1 = start1->next;
		start2 = start2->next;
	}
	else
		return;
}