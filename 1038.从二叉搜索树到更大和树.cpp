/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
 * 
 * 参考树的三种遍历方法，使用右根左的顺序遍历，注意sum要及时更新，也有个root==null 的返回操作
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
    TreeNode* bstToGst(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return root;
        int sum = 0;
        postorder(root,sum);
        return root;
    }
    void postorder(TreeNode* root, int &sum){
        if(!root)
            return;
        if(root->right)
            postorder(root->right, sum);
        if(sum == 0)
            sum = root->val;
        else{
            root->val += sum;
            sum = root->val;
        }
            
        if(root->left)
            postorder(root->left,sum);
    } 
    
};

