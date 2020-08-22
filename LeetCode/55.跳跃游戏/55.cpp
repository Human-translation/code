#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) 
{
	if (nums.size() == 1)
		return true;
	int max = 0;
	for (int i = 0; i < nums.size()-1; i++)
	{
		if (nums[i] == 0 && max <= nums[i] + i)
		{
			return false;
		}
		if (i + nums[i] > max)
			max = i + nums[i];
	}
	if (max >= nums.size() - 1)
		return true;
	return false;
}

//int main()
//{
//	vector<int> arr{ 1,0,1,0 };
//	cout<<canJump(arr);
//	return 0;
//}