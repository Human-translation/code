#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int searchInsert(vector<int>& nums, int target) 
{
	if (target > nums[nums.size() - 1])
		return nums.size();
	int i;
	for (i = nums.size() - 1; i >= 0;)
	{
		if (target <= nums[i])
			i--;
		else
			break;
	}
	return i+1;
}

//
//int main()
//{
//	vector<int> arr{ 1,3,5,6 };
//	cout<<searchInsert(arr, 2);
//	return 0;
//}