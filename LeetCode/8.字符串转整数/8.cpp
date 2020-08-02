#include <iostream>
#include <string>
#include <vector>
using namespace std;


int myAtoi(string str) 
{
	long long num = 0;
	bool flag = true;
	bool fuhao = true;
	bool fuhaoflag = true;
	int fuhaoconut = 0;
	for (auto ch : str)
	{
		if (ch == ' ' && flag)
		{
			continue;
		}
		else if (ch >= '0' && ch <= '9' || ch == '+' || ch == '-')
		{
			flag = false;
			if (ch == '-')
			{
				fuhaoconut++;
				fuhao = false;
			}
			if ((ch == '-' || ch == '+') && !fuhaoflag)
				break;
			if (ch == '+')
			{
				fuhaoconut++;
			}
			if (fuhaoconut > 1)
			{
				break;
			}
			if (num > 2147483647)
				return 2147483647;
			else if (num < -2147483648)
				return 2147483648;

			if (ch >= '0' && ch <= '9')
			{
				fuhaoflag = false;
				num *= 10;
				num += ch - '0';
			}
		}
		else
			break;
	}

	if (!fuhao)
		num = -num;



	
	if (num == 0)
		return 0;
	return num;
}


//int myAtoi(string str)
//{
//	string p;
//	string::iterator it;
//
//	int ans = 0, flag = 0, count = 0;
//	for (it = str.begin(); it < str.end(); it++)
//		if (*it == ' ')
//			continue;
//		else
//			break;
//	for (; it < str.end(); it++)
//	{
//		if (*it == '-' || *it == '+' || (*it >= '0' && *it <= '9'))
//		{
//			if (*it == '-')
//			{
//				if (p.size() != 0)
//					break;
//				count++;
//				flag = 1;
//				continue;
//			}
//			if (*it == '+')
//			{
//				if (p.size() != 0)
//					break;
//				count++;
//				continue;
//			}
//			p.push_back(*it);
//			continue;
//		}
//		else
//			break;
//	}
//	if (count > 1)
//		return 0;
//	it = p.begin();
//	while (it < p.end())
//	{
//		/*ÓëINT_MAX/10±È½Ï*/
//		if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && ((*it) - '0') > 7)) {
//			return flag ? INT_MIN : INT_MAX;
//		}
//		ans = ans * 10 + ((*it) - '0');
//		it++;
//	}
//	return flag ? -ans : ans;
//}
//
//int main()
//{
//	cout << myAtoi("20000000000000000000");
//	return 0;
//}