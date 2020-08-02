#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(int x) {
	string s;
	s += to_string(x);
	int left = 0;
	int right = s.size() - 1;
	while (left < right)
	{
		if (s[left] != s[right])
			return false;
		left++;
		right--;
	}
	return true;
}

//int main()
//{
//	cout << isPalindrome(121);
//	return 0;
//}