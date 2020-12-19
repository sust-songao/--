//struct ListNode*getIntersectionNode(struct ListNode*headA, struct ListNode*headB)
//{
//	struct ListNode*curA, *curB;
//	curA = headA;
//	curB = headB;
//	int lenA = 0, lenB = 0;
//	while (curA)
//	{
//		++lenA;
//		curA = curA->next;
//
//	}
//	while (curB)
//	{
//		++lenB;
//		curB = curB->next;
//	}
//	curA = headA;
//	curB = headB;
//	int gap = abs(lenA - lenB);
//	if (lenA > lenB)
//	{
//		while (gap--)
//		{
//			curA = curA->next;
//		}
//	else
//	{
//		while (gap--)
//			curB = curB->next;
//	}
//	}
//	while (curA == curB)
//	{
//		if (curA == curB)
//			return curA;
//		curA = curA->next;
//		curB = curB->next;
//	}													 00

//	return NULL;	0
//}
//#include<bool.h>
//bool hasCycle(struct ListNode*head)
//{
//	struct listNode*fast = head, *slow = head;
//	while (fast&&fast->next)
//	{
//		fast = fast->next;
//		slow = slow->next;
//		if (fast == slow)
//			return ture;
//	}
//	return false;
//}
//struct ListNode*detectCycle(structNode*head)
//{
//	struct ListNode*cur = hasCycle(head);
//	if (cur)
//	{
//		while (cur)
//		{
//			if (cur == head)
//				return cur;
//			cur = cur->next;
//			head = head->next;
//
//		}
//
//	}	
//	return NULL;
//}		
//
//