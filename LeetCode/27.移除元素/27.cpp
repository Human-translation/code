#include <iostream>
#include <vector>
#include <string>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int i = 0;
	while (i < nums.size())
	{
		if (nums[i] == val)
		{
			nums.erase(nums.begin() + i);
			continue;
		}
		i++;
	}
	return nums.size();
}