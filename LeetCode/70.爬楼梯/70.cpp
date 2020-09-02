#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int climbStairs(int n)
{
	int dp_i_1 = 1;
	int dp_i_2 = 1;
	int dp_i = dp_i_1;
	for (int i = 2; i <= n; i++)
	{
		dp_i = dp_i_1 + dp_i_2;
		dp_i_1 = dp_i_2;
		dp_i_2 = dp_i;
	}
	return dp_i;
}