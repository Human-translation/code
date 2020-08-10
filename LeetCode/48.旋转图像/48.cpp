#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


void rotate(vector<vector<int>>& matrix) {
	int left = 0, right = matrix[0].size() - 1, up = 0, back = matrix.size() - 1;
	for (int i = 0; i < matrix.size() / 2; i++)
	{
		for (int j = 0; j < right - left; j++)
		{
			int tmp = matrix[back - j][left];
			matrix[back - j][left] = matrix[back][right - j];
			matrix[back][right - j] = matrix[up + j][right];
			matrix[up + j][right] = matrix[up][left + j];
			matrix[up][left + j] = tmp;
		}
		left++;
		right--;
		up++;
		back--;
	}
}