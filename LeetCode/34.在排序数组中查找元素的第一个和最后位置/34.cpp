#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target) 
{
	vector<int> arr;
	auto it = find(nums.begin(), nums.end(), target);
	if (it == nums.end())
	{
		arr.push_back(-1);
		arr.push_back(-1);
	}
	else
	{
		int count = 0;
		arr.push_back(it - nums.begin());
		it++;
		while (it!=nums.end() && *it == target)
		{
			it++;
			count++;
		}
		arr.push_back(arr[0] + count );
	}
	return arr;
}


//int main()
//{
//	vector<int> arr{ 1};
//	searchRange(arr, 1);
//	return 0;
//}