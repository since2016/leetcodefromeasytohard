/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 * 
 * 将nums中每个数字，都添加到现有到子集中，构成新到子集
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        res.push_back(subset);
        for (int it:nums)
        {
            int n = res.size();
            for (int i = 0; i < n; i++)
            {
                subset = res[i];
                subset.push_back(it);
                res.psuh_back(subset);
            }
            
        }
        return res;
        
    }
};

