#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string jishuan(string str1, string str2)
{
	vector<int> arr(str1.size() + str2.size());
	string str;
	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			arr[i + j] += (str1[i] - '0')*(str2[j] - '0');
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] >= 10)
		{
			arr[i + 1] += (arr[i] / 10);
			arr[i] %= 10;
		}
	}

	for (int i = arr.size()-1; i >= 0; i--)
	{
		if (i == arr.size() - 1 && arr[arr.size() - 1] == 0)
		{
			continue;
		}
		else
		{
			str += arr[i] + '0';
		}

	}
	return str;
}

string fanzhuan(string num)
{
	int left = 0;
	int right = num.size() - 1;
	while (left < right)
	{
		char tmp = num[left];
		num[left] = num[right];
		num[right] = tmp;
		left++;
		right--;
	}
	return num;
}

string multiply(string num1, string num2)
{
	if ((num1.size() == 1 && num1[0] == '0') || (num2.size() == 1 && num2[0] == '0'))
	{
		return "0";
	}

	string str1 = fanzhuan(num1);
	string str2 = fanzhuan(num2);
	
	return jishuan(str1, str2);
}

//int main()
//{
//	cout << multiply("2", "3") << endl;
//	return 0;
//}