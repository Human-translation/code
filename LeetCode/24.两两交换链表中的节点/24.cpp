#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k)
{
	ListNode* node = head;
	ListNode* cur2;
	vector<ListNode*> arr;
	while (node)
	{
		cur2 = node;
		node = node->next;
		cur2->next = NULL;
		arr.push_back(cur2);
	}
	int count = arr.size() / k;
	int left = 0, right = left + k - 1;
	for (int i = 0; i < count; i++)
	{
		while (left < right)
		{
			ListNode* cur = arr[left];
			arr[left] = arr[right];
			arr[right] = cur;
			left++;
			right--;
		}
		left = (i + 1) * k;
		right = left + k - 1;
	}
	for (int i = 1; i < arr.size(); i++)
	{
		arr[i - 1]->next = arr[i];
	}
	arr[arr.size() - 1]->next = NULL;
	return arr[0];
}

ListNode* swapPairs(ListNode* head) {
	if (!head)
		return NULL;
	return reverseKGroup(head, 2);
}