/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 * 
 * 递归做法， 最初空字符串，在递归函数中，字符串加上左括号，左数减一，
 * 加上右括号，右数减一，左数不能小于右数，左数和右数都要大于0， 当左右数都为0,将字符串加入到vector中
 * 
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("", res, n, n);
        return res;
    }
    void helper(string s, vector<string>& res, int left, int right){
        if (left==0&&right==0)
        {
            res.push_back(s);
            return;
        }
        if(left>right || left<0 || right<0)
            return;
        helper(s+"(", res, left-1,right);
        helper(s+")", res, left, right-1);
    }
};

