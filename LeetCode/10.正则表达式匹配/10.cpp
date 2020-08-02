#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool isMatch(string s, string p)
{
	if (p.empty())
	{
		return s.empty();
	}

	bool same = !s.empty() && (s[0] == p[0] || p[0] == '.');
	if (p.size() >= 2 && p[1] == '*')
	{
		return isMatch(s, p.substr(2)) || (same && isMatch(s.substr(1), p));
	}
	else
		return same && isMatch(s.substr(1), p.substr(1));

}


int main()
{
	cout << isMatch("mississippi","mis*is*p*.");
	return 0;
}

