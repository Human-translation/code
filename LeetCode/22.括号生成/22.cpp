#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string s;
vector<string> arr;
vector<int> bit;
void run(int count,int num)
{
	if (count == num)
	{
		if (s[num - 1] == ')')
			arr.push_back(s);
	}

	for (int i = 0; i <= 1; i++)
	{
		if (s.size() > 0 && s[0] == ')')
			break;
		if (bit[0] > bit[1])
			break;
		
		if (i == 0 && bit[i] > 0)
		{
			bit[i]--;
			s += '(';
			run(count + 1, num);
			s.pop_back();
			bit[i]++;
		}
		else if (i == 1 && bit[i] > 0)
		{
			bit[i]--;
			s += ')';
			run(count + 1, num);
			s.pop_back();
			bit[i]++;
		}
	}
}

vector<string> generateParenthesis(int n) {
	bit.resize(2);
	bit[0] += n;
	bit[1] += n;
	run(0, n * 2);
	return arr;
}
//
//int main()
//{
//	generateParenthesis(3);
//	return 0;
//}