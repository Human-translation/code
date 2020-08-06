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



ListNode* reverseKGroup(ListNode* head, int k) {
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


int main()
{
	ListNode* head = new ListNode(1);
	ListNode* cur = new ListNode(2);
	ListNode* cur2 = new ListNode(3);
	ListNode* cur3 = new ListNode(4);
	ListNode* cur4 = new ListNode(5);
	head->next = cur;
	cur->next = cur2;
	cur2->next = cur3;
	cur3->next = cur4;
	head = reverseKGroup(head, 3);
	while (head)
	{
		cout << head->val << ' ';
		head = head->next;
	}
	return 0;
}