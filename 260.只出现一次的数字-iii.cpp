/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 * 位运算，要比较某一位是否为1,需把该数右移，然后与1做与运算。
 */
class Solution {
public:
    int isbit1(int num, int cnt){
        num>>=cnt;
        return num&1;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        int tmp = 1, cnt=0;
        while ((tmp&res)==0)
        {
            tmp<<=1;
            cnt++;
        }
        int res1=0, res2=0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (isbit1(nums[i],cnt)==1)
            {
                res1^=nums[i];
            }
            else{
                res2^=nums[i];
            }
            
        }
        vector<int> result = {res1, res2};
        return result;
    }
};

