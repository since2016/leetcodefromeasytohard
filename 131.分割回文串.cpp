/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
class Solution {
public:

    bool parliment(string s, int l, int r){
        while (l<r)
        {
            if (s[l]!=s[r])
            {
                return false;
            }
            l++,r--;
        }
        return true;
    }
    
    void partitiondfs(vector<vector<string>> &res, vector<string> &tmp, int index,string s){
        if (s.size()==index)
        {
            res.emplace_back(tmp);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (parliment(s, index, i))
            {
                tmp.push_back(s.substr(index, i-index+1));
                partitiondfs(res, tmp, i+1, s);
                tmp.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        int index = 0;
        if (s.size()==0)
        {
            return res;
        }
        partitiondfs(res, tmp, index, s);
        return res;
    }

};

