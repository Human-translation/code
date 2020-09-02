#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m);
	for (int i = 0; i < m; i++)
		dp[i].resize(n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
			{
				dp[0][0] = grid[0][0];
				continue;
			}
			if (i == 0)
			{
				dp[i][j] = dp[i][j - 1] + grid[i][j];
				continue;
			}
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + grid[i][j];
				continue;
			}
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}
	return dp[m - 1][n - 1];
}