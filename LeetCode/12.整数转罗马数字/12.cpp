#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



string intToRoman(int num) 
{
	int i = 0;
	string s;
	vector<int> arr{ 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
	vector<string> str{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	while (num > 0)
	{
		if (num - arr[i] >= 0)
		{
			num -= arr[i];
			s += str[i];
		}
		else
		{
			i++;
		}
	}
	return s;
}


//int main()
//{
//	cout << intToRoman(58);
//	return 0;
//}