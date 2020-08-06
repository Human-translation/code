#include <iostream>
#include <vector>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
	if (haystack.find(needle) == haystack.npos)
		return -1;
	return haystack.find(needle);
}

