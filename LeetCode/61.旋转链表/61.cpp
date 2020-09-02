#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



//ListNode* rotateRight(ListNode* head, int k) {
//	if (!head || !head->next) return head;
//	ListNode* HEAD = head;
//	int count = 1;
//	while (HEAD->next)
//	{
//		count++;
//		HEAD = HEAD->next;
//	}
//	HEAD->next = head;
//	k = count - (k % count);
//	for (int i = 0; i < k; i++)
//	{
//		HEAD = HEAD->next;
//		head = head->next;
//	}
//	HEAD->next = NULL;
//	return head;
//}