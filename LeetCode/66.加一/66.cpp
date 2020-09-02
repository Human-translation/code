#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


vector<int> plusOne(vector<int>& digits)
{
	vector<int>::iterator it = digits.begin();
	digits[digits.size() - 1]++;
	for (int i = 1; i < digits.size(); i++)
	{
		if (digits[digits.size() - i] > 9)
		{
			digits[digits.size() - i] = 0;
			digits[digits.size() - i - 1]++;
		}
	}
	if (digits[0] > 9)
	{
		digits[0] = 0;
		it = digits.insert(it, 1);
	}
	return digits;
}