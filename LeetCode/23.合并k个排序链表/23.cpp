#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//{
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
//
//ListNode* mergeKLists(vector<ListNode*>& lists) {
//	if (!lists.size())
//		return NULL;
//	int num = lists.size() / 2;
//	int len = lists.size();
//	while (num > 0 && len > 0)
//	{
//		int flag = false;
//		for (int i = num; i < len; i++)
//		{
//			if (i == len - 1 && len % 2 == 1)
//			{
//				lists[i - num] = lists[i];
//				flag = true;
//			}
//
//			else
//				lists[i - num] = mergeTwoLists(lists[i], lists[i - num]);
//		}
//		len /= 2;
//		if (flag)
//			len++;
//		num = len / 2;
//	}
//	return lists[0];
//}