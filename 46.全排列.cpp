/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 * 1、 使用visited数组标定数字是否加入数组中，然后回溯
 * 2、 使用交换不同位置的两个数字，然后回溯
 */
// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         int size = nums.size();
//         vector<vector<int>> res;
//         if (size==0)
//         {
//             return res;
//         }
//         vector<bool> visited(size, false);
//         vector<int> current;
//         dfs(nums, visited, current ,res, 0);
//         return res;
//     }
//     void dfs(vector<int>& nums,vector<bool> &visited, vector<int> &current, vector<vector<int>> &res, int idx){
//         if (idx==nums.size())
//         {
//             res.emplace_back(current);
//             return;
//         }
//         for(int i=0;i<nums.size();i++){
//             if (!visited[i])
//             {
//                 visited[i]=true;
//                 current.emplace_back(nums[i]);
//                 dfs(nums,visited,current, res,idx+1);
//                 visited[i]=false;
//                 current.pop_back();
//             }    
//         } 
//     }
// };

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        if (size==0)
        {
            return res;
        }
        int l=0,r = size-1;
        vector<int> current;
        permutate(nums, res, l, r);
        return res;
    }
    void permutate(vector<int>& nums,vector<vector<int>> &res, int l, int r){
        if (l==r){
            res.emplace_back(nums);
            return;
        }
        for (int i = l; i <= r; i++)
        {
            swap(nums[l], nums[r]);
            permutate(nums, res, l+1, r);
            swap(nums[l], nums[r]);
        }
        
    }
};


