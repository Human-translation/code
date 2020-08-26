#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(3, 3)
        int count = 1; // 用来计数
        int offset = 1; // 每一圈循环，需要偏移的位置
        int i,j;
        while (loop --) {        
            i = startx;
            j = starty; 

            // 下面的四个循环就是模拟转了一圈 
            for (j = starty; j < starty + n - offset; j++) {
                res[startx][j] = count++;
            }
            for (i = startx; i < startx + n - offset; i++) {
                res[i][j] = count++;
            }
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈，遍历的长度
            offset += 2;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};