#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string countAndSay(int n) {
	string result = "";
	result = "1";
	for (int i = 1; i < n; i++)
	{
		string tmp = "";
		for (int j = 0; j < result.size(); j++)
		{
			int count = 1;
			while (j + 1 < result.size() && result[j + 1] == result[j])
			{
				count++;
				j++;
			}
			tmp += to_string(count) + result[j];
		}
		result = tmp;
	}
	return result;
}
