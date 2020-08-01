#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


int lengthOfLongestSubstring(string s) 
{
	int maxnum = 0;
	int count = 0;
	unordered_map<char, int> map;
	int slow = 0;
	int fast = 0;
	for (; fast < s.size(); fast++)
	{
		if (!map.count(s[fast]) || map[s[fast]] == -1)
		{
			map[s[fast]] = fast;
			count++;
		}
		else
		{
			int num = map[s[fast]];
			count -= (num - slow );
			for (; slow <= num; slow++)
			{
				map[s[slow]] = -1;
			}
			map[s[fast]] = fast;
		}
		maxnum = max(maxnum,count);
	}
	return maxnum;
}

//int main()
//{
//	cout << lengthOfLongestSubstring("abcabcbb") << endl;
//	return 0;
//}