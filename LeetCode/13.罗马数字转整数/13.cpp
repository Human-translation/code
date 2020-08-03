#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


int romanToInt(string s) {
	unordered_map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10},{'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
	int num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (m[s[i]] < m[s[i + 1]])
		{
			num -= m[s[i]];
			continue;
		}
		num += m[s[i]];
	}
	return num;
}