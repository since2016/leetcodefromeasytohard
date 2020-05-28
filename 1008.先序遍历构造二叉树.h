/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // 采用前序遍历构造二叉搜索树。
 //只需要找到[left, right]范围内，比preorder[left] 大的第一个数，就是右子树第一个节点值。然后用前序遍历模板。
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int length = preorder.size();
        return constructFromPreorder(preorder, 0, length-1);
    }
    TreeNode* constructFromPreorder(vector<int>& preorder, int left, int right){
        if(left > right)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[left]);
        int mid = left+1;
        for(;mid<=right;mid++){
            if(preorder[mid]>preorder[left])
                break;
        }

        root->left = constructFromPreorder(preorder, left+1, mid-1);
        root->right = constructFromPreorder(preorder, mid, right);
        return root;
    }
};