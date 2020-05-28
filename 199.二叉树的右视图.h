/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // 看右视图，就是可以看成是寻找每层的最后一个节点。
 // 可以采用层序遍历方法，当cur_lev=1的时候，就是找到了该层最后一个节点。
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        int cur_lev = 1, next_lev = 0;
        while(!node_queue.empty()){
            TreeNode* node = node_queue.front();
            if(cur_lev == 1)
                res.push_back(node->val);
            node_queue.pop();
            cur_lev-- ;
            if(node->left){
                node_queue.push(node->left);
                next_lev++;
            }
            if(node->right){
                node_queue.push(node->right);
                next_lev++;
            }
            if(cur_lev==0){
                cur_lev = next_lev;
                next_lev=0;
            }
        }
        return res;
    }
};