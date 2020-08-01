#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> arr;
	unordered_set<int> myset;
	for (auto ch : nums)
	{
		myset.insert(ch);
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (myset.count(target - nums[i]))
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (i == j)
					continue;
				if (nums[j] == target - nums[i])
				{
					arr.push_back(i);
					arr.push_back(j);
					return arr;
				}
			}
		}
	} 
	return arr;
}

//int main()
//{
//	vector<int> nums{ 3,2,4};
//	twoSum(nums, 6);
//	return 0;
//}