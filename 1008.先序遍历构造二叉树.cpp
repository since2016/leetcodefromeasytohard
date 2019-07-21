/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 先序遍历构造二叉树
 * 
 * 先序遍历的第一个数是根结点，然后左子树是小于根结点，右子树大于根结点，以此划分数组
 * 对每一部分数组再构造根结点，再划分左右子树的数组。
 * 注意需要考虑下一阶段的左子树数组要剔除根结点的数字
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
    int partition(vector<int>& preorder, int l, int r){
        if(l>=r)
            return l;
        int key = preorder[l],i=l;
        for(;i<r;i++){
            if(preorder[i]>key)
                break;
        }
        return i;
    }
    
    TreeNode* constructBST(vector<int>& preorder, int l, int r){
        if (l>=r)
            return NULL;
        TreeNode* root = new TreeNode(preorder[l]);
        int idx = partition(preorder, l, r);
        if (idx > l)
        // 要剔除根结点的数字
            root->left = constructBST(preorder,l+1,idx);
        if (idx < r)
            root->right = constructBST(preorder, idx, r);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
            return NULL；
        TreeNode* root = new TreeNode(preorder[0]);
        int idx = partition(preorder, 0, preorder.size());
        if(idx > 0 )
        // 要剔除根结点的数字
            root->left = constructBST(preorder, 1, idx);
        if (idx < preorder.size())
            root->right = constructBST(preorder, idx, preorder.size());
        return root;
    }
};

