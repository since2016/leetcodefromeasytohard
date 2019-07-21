/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 *  求一个数的2进制有多少个1， 可以用 cnt = 0;while(n){ n = n&(n-1); cnt++;}
 * 来做，本题使用前面求过的数的个数加一就可以了。
 * 
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i = 1; i < num+1; i++)
        {
            res[i] = res[i&(i-1)]+1;
        }
        return res;
    }
};

