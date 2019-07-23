/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 * 还是回溯的方法，有cursum 和 k 作为标志位
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> oneresult;
        int cursum = 0,start=1;
        dfs(res, oneresult, cursum, start,k, n);
        return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> &oneresult, int cursum, int start, int k,int n){
        if (k==0&&cursum == n)
        {
            res.emplace_back(oneresult);
        }
        for (int i = start; i <= 9; i++)
        {
            cursum += i;
            k--;
            oneresult.emplace_back(i);
            dfs(res, oneresult, cursum, i+1, k, n);
            oneresult.pop_back();
            k++;
            cursum -= i;
        }
    }
};

