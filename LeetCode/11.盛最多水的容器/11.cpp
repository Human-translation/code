#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) 
{
	int i = 0;
	int j = height.size() - 1;
	int area = 0;
	int MaxArea = 0;
	while (i < j)
	{
		area = (j - i) * min(height[j], height[i]);
		MaxArea = max(MaxArea, area);
		if (height[j] < height[i])
		{
			j--;
		}
		else
			i++;
	}
	return MaxArea;
}

//int main()
//{
//	vector<int> arr{ 1,8,6,2,5,4,8,3,7 };
//	cout<<maxArea(arr);
//	return 0;
//}