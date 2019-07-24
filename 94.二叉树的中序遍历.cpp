/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 * 使用递归与非递归
 * 非递归， 优先压入左子树，当左子树为空，再考虑右子树
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
// 递归解法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        inorder(res, root);
        return res;
    }
    void inorder(vector<int> &res, TreeNode* root){
        if(!root)
            return;
        inorder(res, root->left);
        res.push_back(root->val);
        inorder(res, root->right);
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> st;
        TreeNode* curnode = root;
        while (curnode!=NULL || !st.empty())
        {
            while(curnode != NULL){
                st.push(curnode);
                curnode = curnode->left;
            }
            curnode = st.top();
            st.pop();
            res.push_back(curnode->val);
            curnode = curnode->right;
        }
        return res;
    }
};

