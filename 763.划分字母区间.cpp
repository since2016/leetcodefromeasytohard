/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 * 要先搞清楚每个字母最大的下标。对先取定一个范围，然后再扩充，停止的条件是下标和范围右界相同。
 */
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> alpha(26, -1);
        vector<int> res;
        for (int i = 0; i < S.size(); i++)
        {
            alpha[S[i]-'a'] = i;
        }
        int l=-1, r=0,i=0;
        string s = "";
        while (i<S.size())
        {
            r = alpha[S[i]-'a'] > r ? alpha[S[i]-'a']:r;
            s += S[i];
            if (i==r)
            {
                res.push_back(r-l);
                s = "";
                l=i;
            }
            i++;
        }
        return res;
    }
};

