/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    void preorder(TreeNode* root, int val){
        if (root->val < val)
        {
            if (!root->right)
            {
                TreeNode* node = new TreeNode(val);
                root->right = node;
                return;
            }
            else
            {
                preorder(root->right, val);
            }
        }
        else
        {
            if (!root->left)
            {
                TreeNode* node = new TreeNode(val);
                root->left = node;
                return;
            }
            else
            {
                preorder(root->left,val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
        {
            TreeNode* root = new TreeNode(val);
            return root;
        }
        preorder(root, val);
        return root;
    }
};

