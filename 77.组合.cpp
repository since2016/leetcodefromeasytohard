/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 * 还是采用传统的递归回溯方法。
 * 改进措施，是对于一些情况可以剪枝操作，提前避免进入一些没有结果的情况
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n<k)
        {
            return res;
        }
        vector<int> oneresult;
        int idx = 1;
        helper(res, oneresult, n, k, idx);
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> &oneresult, int n, int k, int idx){
        if (oneresult.size() == k)
        {
            res.emplace_back(oneresult);
            return;
        }
        for (int i = idx; i < n-(k - oneresult.size())+2; i++)
        {
            oneresult.emplace_back(i);
            helper(res, oneresult, n, k, i+1);
            oneresult.pop_back();
        }
    }
};

