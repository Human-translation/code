#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> brr;
	vector<int> arr;
	for (int i = 0; i < intervals.size(); )
	{
		if (!arr.size())
		{
			arr.push_back(intervals[i][0]);
			arr.push_back(intervals[i][1]);
		}
		else if (arr[1] >= intervals[i][0])
		{
			arr[1] = (max(intervals[i][1], arr[1]));
		}
		else
		{
			brr.push_back(arr);
			arr.pop_back();
			arr.pop_back();
			continue;
		}
		i++;
	}
	if (arr.size())
	{
		brr.push_back(arr);
	}
	return brr;
}


//int main()
//{
//	vector<vector<int>> arr;
//	vector<int> num1{ 2,3 };
//	vector<int> num2{ 4,5 };
//	vector<int> num3{ 6,7 };
//	vector<int> num4{ 1,10 };
//	arr.push_back(num4);
//	arr.push_back(num2);
//	arr.push_back(num1);
//	arr.push_back(num3);
//	merge(arr);
//	return 0;
//}