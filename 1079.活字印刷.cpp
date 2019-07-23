/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */
class Solution {
public:
    void dfs(unordered_set<string> &seqs, vector<bool> &visited,string tiles, string oneresult, int nown, int n){
        if (nown >= n)
        {
            seqs.insert(oneresult);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                oneresult+=tiles[i];
                visited[i]=true;
                dfs(seqs, visited, tiles, oneresult, nown+1, n);
                visited[i]=false;
                oneresult.pop_back();
            }
            
        }  
    }
    int numTilePossibilities(string tiles) {
        int len = tiles.size();
        vector<bool> visited(len, false);
        string oneresult = "";
        unordered_set<string> seqs;
        for (int n = 1; n <= len; n++)
        {
            for (int i = 0; i < n; i++)
            {
                dfs(seqs, visited, tiles,oneresult, i, n);
            }
            
        }    
        return seqs.size();
    }
};