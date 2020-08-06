#include <iostream>
#include <vector>
#include <string>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	if (!nums.size())
		return 0;
	int i = 0, j = 1;
	while (j < nums.size())
	{
		while (j < nums.size() - 1 && nums[i] == nums[j])
			j++;
		if (nums[i] != nums[j])
		{
			i++;
			nums[i] = nums[j];
		}
		j++;
	}
	return i + 1;
}



