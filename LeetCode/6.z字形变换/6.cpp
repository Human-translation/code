#include <iostream>
#include <string>
#include <vector>
using namespace std;

string run(vector<vector<char>> &arr)
{
	string str;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			str += arr[i][j];
		}
	}
	return str;
}

string convert(string s, int numRows) 
{
	int i = 0;
	bool flag = true;
	vector<vector<char>> arr(numRows);
	for (auto ch : s)
	{
			arr[i].push_back(ch);
			if (flag)
				i++;
			else
				i--;
			if (i == numRows)
			{
				i -= 2;
				flag = false;
			}
			if (i == -1)
			{
				i += 2;
				flag = true;
			}
	}
	return  run(arr);
}

//string convert(string s, int numRows) {
//
//	if (numRows == 1) return s;
//
//	vector<string> rows(min(numRows, int(s.size())));
//	int curRow = 0;
//	bool goingDown = false;
//
//	for (char c : s) {
//		rows[curRow] += c;
//		if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
//		curRow += goingDown ? 1 : -1;
//	}
//
//	string ret;
//	for (string row : rows) ret += row;
//	return ret;
//}
//
//
//int main()
//{
//	cout<<convert("ab", 1);
//	return 0;
//}