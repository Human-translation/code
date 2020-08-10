#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		result.push_back(nums);
		while (next_permutation(nums.begin(), nums.end())) {
			result.push_back(nums);
		}
		return result;
	}



//int main()
//{
//	vector<int> arr{ 1,1,2 };
//	permute(arr);
//	return 0;
//}