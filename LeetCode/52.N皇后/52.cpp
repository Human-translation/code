#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<vector<string>> arr;
vector<int> brr;
int number = 0;

bool judge(vector<int> &brr)
{
	if (brr.size() == 0 || brr.size() == 1)
		return true;

	for (int i = brr.size() - 1; i > 0; i--)
	{
		for(int j=i-1;j>=0;j--)
		if (brr[j]-brr[i] == j-i || brr[j] - brr[i] == i-j)
		{
			return false;
		}
	}
	return true;
}

void run(vector<int> &bit,int count,int num)
{
	if (count == num && judge(brr))
	{
		for (auto ch : brr)
		{
			cout << ch << ' ';
		}
		cout << endl;
		number++;
		return;
	}

	for (int i = 0; i < num; i++)
	{
		if (bit[i] == 1)
		{
			bit[i]--;
			brr.push_back(i + 1);
			run(bit, count + 1, num);
			brr.pop_back();
			bit[i]++;
		}
	}
}

int totalNQueens(int n) 
{
	vector<int> bit(n, 1);
	run(bit, 0, n);
	return number;
}

vector<vector<string>> solveNQueens(int n) 
{
	vector<int> bit(n,1);
	run(bit, 0, n);
	return arr;
}

//int main()
//{
//	solveNQueens(5);
//	cout << number << endl;
//	return 0;
//}