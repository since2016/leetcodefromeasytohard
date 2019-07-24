/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 * gray编码 g(i) = i ^ (i/2)
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1<<n;
        vector<int> res;
        for (int i = 0; i < size; i++)
        {
            res.push_back(i^(i>>1));
        }
        return res;
    }
};

