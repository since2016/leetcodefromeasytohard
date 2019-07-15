/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 * 
 * 分段，每段找到最大的数作为根，在分左右两边再做同样的事情。
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int root_idx = posemax(nums, 0, nums.size())
        TreeNode* root = new TreeNode(nums[root_idx]);
        if(root_idx>0)
            root->left = constructBT(nums, 0, root_idx);
        if(root_idx<nums.size()-1)
            root->right = constructBT(nums,root_idx+1, nums.size());
        return root;

    }
    TreeNode* constructBT(vector<int>& nums, int begin, int end){
        int idx = posemax(nums, begin, end);
        TreeNode* node = new TreeNode(nums[idx]);
        if (idx>begin)
        {
            node->left = constructBT(nums, begin,idx);
        }
        if (idx<end-1)
        {
            node->right = constructBT(nums, idx+1, end);
        }
        
        return node;
    }

    int posemax(vector<int>& nums ,int begin, int end){
        int idx = begin, max_num = nums[begin];
        for(int i=begin;i<end;i++){
            if(max_num<nums[i]){
                idx = i;
                max_num = nums[i]
            }
        }
        return idx;
    }
};

