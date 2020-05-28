/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 对于任意一颗树而言，前序遍历的形式总是 [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ] 即根节点总是前序遍历中的第一个节点。
 // 而中序遍历的形式总是 [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
//  可以采用前序遍历方式重新构造出树结构。 需要搞清楚前序遍历和中序遍历中分界点的位置
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_left = 0, pre_right = preorder.size()-1;
        int in_left = 0, in_right = inorder.size()-1;
        if(pre_right != in_right)
            return NULL;
        return constructHelper(preorder, pre_left, pre_right, inorder, in_left, in_right);
    }
    TreeNode* constructHelper(vector<int>& preorder, int pre_left, int pre_right, vector<int>& inorder, int in_left,int in_right){
        if(pre_left > pre_right || in_left > in_right){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pre_left]);
        int in_mid = in_left;
        for(;in_mid <= in_right;in_mid++){
            if(inorder[in_mid]==preorder[pre_left])
                break;
        }
        if(in_mid>in_left)
            root->left = constructHelper(preorder, pre_left+1, pre_left+in_mid-in_left, inorder, in_left, in_mid-1);
        if(in_mid < in_right)
            root->right = constructHelper(preorder, pre_left+in_mid-in_left+1, pre_right, inorder, in_mid+1, in_right);

        return root;
    }

};