/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 *  使用中序遍历， 参数需要是引用，因为需要改动
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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        inorder(root, k,res);
        return res;
    }
    void inorder(TreeNode* root, int &k, int &res){
        if (!root||k<=0)
        {
            return;
        }
        inorder(root->left, k, res);
        // 对根结点的处理，k--, 然后当k==0就得到结果
        k--;
        if(k==0)
            res = root->val;
        inorder(root->right, k, res);
    }
};

