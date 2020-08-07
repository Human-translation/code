#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<vector<int>> ptr;
unordered_set<string> set;
vector<int> arr;
string s;

string zhuanhuan(vector<int> arr)
{
	string s;
	for (auto ch : arr)
		s += ch + '0';
	sort(s.begin(), s.end());
	return s;
}

void run(vector<int>& candidates, int num, int target)
{
	if (num == target)
	{
		string str = zhuanhuan(arr);

		if (!set.count(str))
		{
			set.insert(str);
			ptr.push_back(arr);
			cout << str << endl;
		}

	}

	for (int i = 0; i < candidates.size(); i++)
	{
		if (num > target)
			return;

		arr.push_back(candidates[i]);
		num += candidates[i];
		run(candidates, num, target);
		arr.pop_back();
		num -= candidates[i];
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	run(candidates, 0, target);
	return ptr;
}