#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int maxSubArray(vector<int>& nums)
{
	vector<int> dp;
	if (nums.empty())
		return 0;
	dp.resize(nums.size());
	for (int i = 0; i < nums.size(); i++)
	{
		if (i == 0)
		{
			dp[i] = nums[i];
			continue;
		}
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);
	}
	int max = dp[0];
	for (auto ch : dp)
		if (ch > max)
			max = ch;
	return max;
}