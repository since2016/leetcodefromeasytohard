/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 * 
 * 先将链表转换成vector, 排序后的顺序。然后取中点做root
 * 
 * 给定列表中的中间元素将会作为二叉搜索树的根，该点左侧的所有元素递归的去构造左子树，
 * 同理右侧的元素构造右子树。这必然能够保证最后构造出的二叉搜索树是平衡的。
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    vector<ListNode*> node;
    TreeNode* sortedListToBST(ListNode* head) {
        while (head)
        {
            node.push_back(head);
            head = head->next;
        }
        TreeNode* root = dfs(0, node.size()); 
        return root;
        
    }
    TreeNode* dfs(int l, int r){
        if (l>=r)
        {
            return NULL;
        }
        int mid = l+(r-l)/2;
        TreeNode* root = new TreeNode(node[mid]->val);
        root->left = dfs(l, mid);
        root->right = dfs(mid+1, r);
        return root;
    }
};

