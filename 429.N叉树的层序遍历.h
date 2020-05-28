/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 采用层序遍历的模板去做就行。一开始注意root == NULL；

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<Node*> node_queue;
        node_queue.push(root);
        int cur_lev = 1, next_lev = 0;
        vector<int> level_val;
        while(!node_queue.empty()){
            Node* node = node_queue.front();
            level_val.push_back(node->val);
            node_queue.pop();
            cur_lev--;
            for(int i=0;i<node->children.size();i++){
                node_queue.push(node->children[i]);
                next_lev++;
            }
            if(cur_lev == 0){
                cur_lev = next_lev;
                next_lev=0;
                res.push_back(level_val);
                level_val = {};
            }
        }
        return res;
    }
};