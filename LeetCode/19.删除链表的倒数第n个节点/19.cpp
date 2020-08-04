#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
	vector<ListNode*> arr;
	ListNode* node = head;

	while (node != NULL)
	{
		arr.push_back(node);
		node = node->next;
	}

	int num = arr.size() - n;
	if (num == 0)
	{
		head = head->next;
	}
	else if (num == arr.size() - 1)
	{
		node = arr[arr.size() - 2];
		node->next = NULL;
	}
	else
	{
		node = arr[num - 1];
		node->next = arr[num]->next;
	}

	return head;
}
//
//int main()
//{
//	int a[4] = { 0,2,4,8};
//	int* ptr = new int[4];
//	ptr = a;
//	cout << ptr[1] << endl;
//	return 0;
//}
