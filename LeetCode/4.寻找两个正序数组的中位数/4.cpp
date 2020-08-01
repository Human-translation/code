#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

double run(vector<int>& nums1, vector<int>& nums2, int totalpos)
{
	int pos = totalpos / 2;
	int number1 = 0;
	int number2 = 0;
	while (pos)
	{
		if (pos > nums1.size() || pos > nums2.size())
			pos = min(nums1.size(),nums2.size());
		if (nums1[pos-1+number1] > nums2[pos-1+ number2])
		{
			number2 += pos;
		}
		else if (nums1[pos-1+ number1] < nums2[pos-1+ number2])
		{
			number1 += pos;
		}
		else if (nums1[pos-1+ number1] == nums2[pos-1+ number2])
		{
			number2 += pos;
		}
		totalpos -= pos;
		pos = totalpos / 2;
		if (number1 >= nums1.size())
		{
			return nums2[number2 + totalpos -1];
		}
		else if (number2 >= nums2.size())
		{
			return nums1[number1 + totalpos-1];
		}
	}
	return nums1[number1] < nums2[number2] ? nums1[number1] : nums2[number2];
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	if (!nums1.size())
	{
		if (nums2.size() % 2)
		{
			return nums2[nums2.size() / 2];
		}
		else
		{
			return (nums2[(nums2.size()-1) / 2] + nums2[((nums2.size()-1) / 2) + 1])/2.0;
		}
	}
	else if (!nums2.size())
	{
		if (nums1.size() % 2)
		{
			return nums1[nums1.size() / 2];
		}
		else
		{
			return (nums1[(nums1.size() - 1) / 2] + nums1[((nums1.size() - 1) / 2) + 1]) / 2.0;
		}
	}
	int k = nums1.size() + nums2.size();
	if (k%2)
		return run(nums1, nums2, (k+1) / 2);
	return (run(nums1, nums2, k / 2) + run(nums1, nums2, (k / 2) + 1))/2.0;
}


//int main()
//{
//	vector<int> arr{1,2};
//	vector<int> brr{ 3,4,5,6,7,8,9,10};
//	cout << findMedianSortedArrays(arr,brr) << endl;
//	return 0;
//}