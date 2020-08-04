#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> arr{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
vector<string> ptr;
vector<int> bit;
void dps(string digits, string s, int count, int num)
{
	if (count == num)
	{
		auto it = find(ptr.begin(), ptr.end(), s);
		if (it == ptr.end())
			ptr.push_back(s);
		return;
	}

	for (int i = count; i < num; i++)
	{
		for (int j = 0; j < arr[digits[i] - '0'].size(); j++)
		{
			if (bit[digits[i] - '0'] == 0)
				continue;
			s += arr[digits[i] - '0'][j];
			bit[digits[i] - '0']--;
			dps(digits, s, count + 1, num);
			bit[digits[i] - '0']++;
			s.pop_back();
		}
	}
}

vector<string> letterCombinations(string digits)
{
	if (!digits.size())
		return ptr;
	string s;
	bit.resize(10);
	for (auto ch : digits)
	{
		bit[ch - '0']++;
	}
	dps(digits, s, 0, digits.size());
	return ptr;
}

//int main()
//{
//	for (auto ch : letterCombinations("22"))
//		cout << ch << ' ';
//	cout << endl;
//	return 0;
//}