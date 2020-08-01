#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string ptr;

void run(string arr, int left, int right)
{
	while (left >= 0 && right < arr.size() && arr[left] == arr[right])
	{
		if (ptr.size() < right - left + 1)
		{
			ptr = arr.substr(left, right - left + 1);
		}
		left--;
		right++;
	}
}

string longestPalindrome(string s) {

	for (int i = 0; i < s.size(); i++)
	{
		run(s, i, i);
		run(s, i, i + 1);
	}
	return ptr;
}

int main()
{
	cout << longestPalindrome("babad") << endl;
	return 0;
}