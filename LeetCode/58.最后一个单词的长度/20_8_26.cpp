#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int lengthOfLastWord(string s) 
{
	if (s.size() == 0)
		return 0;
	while (s[s.size() - 1] == ' ')
	{
		s.pop_back();
	}
	string::reverse_iterator pos = find(s.rbegin(), s.rend(), ' ');
	string::reverse_iterator it = s.rbegin();
	int count = 0;
	while (it < pos)
	{
		count++;
		it++;
	}
	return count;
}