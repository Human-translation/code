#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isValid(string s) 
{
	vector<char> arr;
	for (auto ch : s)
	{
		if (ch == '{' || ch == '(' || ch == '[')
		{
			arr.push_back(ch);
		}
		else if (!arr.size() && (ch == ')' || ch == ']' || ch == '}'))
		{
			return false;
		}
		else
		{
			char ptr = arr[arr.size() - 1];
			arr.pop_back();
			if (ch == ')' && ptr != '(')
				return false;
			else if (ch == '}' && ptr != '{')
				return false;
			else if (ch == ']' && ptr != '[')
				return false;
		}
	}
	if (arr.size())
		return false;
	return true;
}

int main()
{
	cout << isValid("()") << endl;
	return 0;
}