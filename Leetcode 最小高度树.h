/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // 最小高度树，需要是二叉搜索树。面对排序的数组，选择中间的树作为根节点。
 // 然后采用前序遍历依次处理左子树和右子树
class Solution {
public:

    TreeNode* preorder(const vector<int>& nums, int left, int right){
        if(left > right)
            return nullptr;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = preorder(nums, left, mid-1);
        root->right = preorder(nums, mid+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return preorder(nums, 0, nums.size()-1);
    }
};