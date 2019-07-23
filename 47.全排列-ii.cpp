/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 * 
 * 还是采用传统的回溯方法， 但是在构造递归树的过程中需要剪枝操作，
 * 解题的关键是
 *  ‘’ 当数组中，有了重复元素的时候，其实也不难，我们可以先把数组排个序，
 *     这样在递归的过程中就可以很容易发现重复的元素。
 *     当发现重复元素的时候，让这一个分支跳过，就达到了“剪枝”的效果，重复的排列就不会出现在结果集中。‘’
 * 前一个数与该数相同，且前一个数没有被访问过。
 * 
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        if(size==0)
            return res;
        sort(nums.begin(), nums.end());
        vector<int> visited(size, false);
        vector<int> oneresult;
        int idx=0;
        dfs(res, oneresult, nums, visited,idx);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> &oneresult, vector<int>& nums,vector<int> &visited, int idx){
        if (idx==nums.size())
        {
            res.emplace_back(oneresult);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                if (i>0 && nums[i]==nums[i-1] && !visited[i-1])
                    continue;
                visited[i] = true;
                oneresult.emplace_back(nums[i]);
                dfs(res, oneresult,nums, visited, idx+1);
                visited[i]=false;
                oneresult.pop_back();
            }           
        } 
    }
};