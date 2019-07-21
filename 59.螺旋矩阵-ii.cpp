/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 * 
 * 循环结束条件是c值 达到n*n。每一个边的开始和结束条件都要算好。
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int j = 0, c = 1;
        while (c<=n*n)
        {
            for (int i = j; i < n-j; i++)
                res[j][i] = c++;
            for (int i = j+1; i < n-j; i++)
                res[i][n-j-1] = c++;
            for (int i = n-j-2; i > j; i--)
                res[n-j-1][i] = c++;
            for (int i = n-j-1; i > j; i--)
                res[i][j] = c++;
            
            j++;
            
        }
        return res;
        
    }
};

