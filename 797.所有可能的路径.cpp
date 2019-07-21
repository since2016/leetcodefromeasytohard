/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 * 使用深度遍历，当node是目标点时候就加到res中，然后回溯搜索下一个点
 */
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int rows= graph.size();
        vector<vector<int>> res;
        vector<int> path;
        int node = 0, target= rows-1;
        path.emplace_back(node);
        SearchPath(graph, node, target,res, path);
        return res;
    }
    void SearchPath(vector<vector<int>>& graph, int node, int target,vector<vector<int>>& res, vector<int> path){
        if (node == target)
        {
            res.emplace_back(path);
            return;
        }
        for (int inode:graph[node])
        {
            path.emplace_back(inode);
            SearchPath(graph, inode, target, res,path);
            path.pop_back();
        } 
        
    }
};

