#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string addBinary(string a, string b)
{
	int al = a.size();
	int bl = b.size();
	while (al < bl)
	{
		a = '0' + a;
		++al;
	}
	while (al > bl)
	{
		b = '0' + b;
		++bl;
	}
	for (int j = a.size() - 1; j > 0; --j)
	{
		a[j] = a[j] - '0' + b[j];
		if (a[j] >= '2')
		{
			a[j] = (a[j] - '0') % 2 + '0';
			a[j - 1] = a[j - 1] + 1;
		}
	}
	a[0] = a[0] - '0' + b[0];
	if (a[0] >= '2')
	{
		a[0] = (a[0] - '0') % 2 + '0';
		a = '1' + a;
	}
	return a;
}