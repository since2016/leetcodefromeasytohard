/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 * 1。要考虑到dfs中cursum 与 target 大小关系， 
 * 2。 要考虑开始的index
 * 
 */
class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int>& oneresult, int start,int cursum, int target,vector<int>& candidates){
        if (cursum == target)
        {
            res.emplace_back(oneresult);
            return;
        }else if(cursum < target){
            for (int i = start; i < candidates.size(); i++)
            {
                cursum += candidates[i];
                oneresult.push_back(candidates[i]);
                dfs(res, oneresult, i,cursum, target, candidates);
                cursum -= candidates[i];
                oneresult.pop_back();
            }            
        }
        else
            return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> oneresult;
        int cursum = 0, start = 0;
        dfs(res, oneresult, start,cursum, target, candidates);
        return res;
    }

};


