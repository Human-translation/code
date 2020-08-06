#include <iostream>
#include <vector>
#include <string>
using namespace std;


void nextPermutation(vector<int>& nums)
{
	if (nums.size() == 1) return;
	int i = nums.size() - 2;
	int j = nums.size() - 1;
	int k = nums.size() - 1;

	while (i >= 0 && nums[i] >= nums[j]) {
		i--;
		j--;
	}
	if (i >= 0) {
		while (nums[i] >= nums[k]) {
			k--;
		}
		swap(nums[i], nums[k]);
	}
	sort(nums.begin() + j, nums.end());
}