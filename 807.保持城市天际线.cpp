/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 * 
 * row_max 存每行最大值，col_max存每列最大值。
 * 再次便利数组，先得到每个位置的天际线（该行最大值与该列最大值的较小那个值），求得与该位置上值的差，对每个差加起来
 * 
 * 
 */
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> row_max, col_max(grid[0]);
        for(int i = 0;i<rows;i++){
            row_max.push_back(grid[i][0]);
            for(int j=0;j<cols;j++){
                row_max[i] = row_max[i]>grid[i][j]?row_max[i]:grid[i][j];
                col_max[j] = col_max[j]>grid[i][j]?col_max[j]:grid[i][j];
            }     
        }
        int count = 0,skyline = 0;
        for(int i=0;i<rows;i++){
            for (int  j = 0; j < cols; j++)
            {
                skyline = row_max[i] < col_max[j]? row_max[i]:col_max[j];
                count += skyline - grid[i][j];
                
            }
            
        }
        return count;
    }
};

