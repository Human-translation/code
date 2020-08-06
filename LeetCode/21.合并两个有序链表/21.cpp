#include <iostream>
using namespace std;


//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
 


//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//	ListNode* head = new ListNode(0);
//	ListNode* ptr = head;
//	ListNode* node = NULL;
//	while (l1 && l2)
//	{
//		if (l1->val <= l2->val)
//		{
//			node = l1;
//			l1 = l1->next;
//			node->next = NULL;
//			ptr->next = node;
//			ptr = node;
//		}
//		else
//		{
//			node = l2;
//			l2 = l2->next;
//			node->next = NULL;
//			ptr->next = node;
//			ptr = node;
//		}
//	}
//	if (l1)
//		ptr->next = l1;
//	if (l2)
//		ptr->next = l2;
//
//	return head->next;
//}