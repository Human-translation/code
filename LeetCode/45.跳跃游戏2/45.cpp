#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int jump(vector<int>& nums) 
{
	if (nums[0]  >= nums.size()-2 )
		return 2;
	vector<int> dp(nums.size(),30000);
	dp[0] = 0;

	for (int i = 0; i < dp.size(); i++)
	{
		for (int j = 1; j <= nums[i]; j++)
		{
			if (i + j <= dp.size() - 1)
			{
				dp[i + j] = min(dp[i] + 1, dp[i + j]);
			}
			else
				break;
		}
	}
	return dp[nums.size() - 1];
}



//int main()
//{
//	vector<int> arr{ 1,2,3 };
//	cout << jump(arr) << endl;
//	return 0;
//}