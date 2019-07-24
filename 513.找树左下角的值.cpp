/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 * 使用层序遍历， 每层最左边的第一个元素当作结果，遍历完就得到最终结果。
 * 要注意每次队列要不为空的情况下
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int curlevel = 1, next = 0;
        int leftnode = root->val;
        while (!q.empty())
        {
            TreeNode* node = q.front();
            if (node->left)
            {
                q.push(node->left);
                next++;
            }
            if (node->right)
            {
                q.push(node->right);
                next++;
            }
            q.pop();
            curlevel--;
            if(curlevel==0){
                curlevel=next;
                next=0;
                if (!q.empty())
                {
                    leftnode = q.front()->val;
                }  
            }
        }
        return leftnode; 
    }
};

