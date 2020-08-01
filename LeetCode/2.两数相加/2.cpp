#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode
{
	ListNode* next;
	int val;
	ListNode(int x)
		:val(x)
		, next(nullptr)
	{}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* head = l1;
	ListNode* head2 = l2;
	while (l1 && l2)
	{
		l1->val += l2->val;
		l2->val = l1->val;
		l1 = l1->next;
		l2 = l2->next;
	}
	if (l2)
	{
		head = head2;
		l2 = head;
		while (l2)
		{
			if (l2->val >= 10)
			{
				l2->val -= 10;
				if (l2->next)
				{

					l2->next->val += 1;
				}
				else
				{
					ListNode* cur = new ListNode(1);
					l2->next = cur;
				}
			}
			l2 = l2->next;
		}
	}
	else
	{
		l1 = head;
		while (l1)
		{
			if (l1->val >= 10)
			{
				l1->val -= 10;
				if (l1->next)
				{

					l1->next->val += 1;
				}
				else
				{
					ListNode* cur = new ListNode(1);
					l1->next = cur;
				}
			}
			l1 = l1->next;
		}
	}

	return head;
}


