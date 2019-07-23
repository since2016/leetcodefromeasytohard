/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 * 使用w2p和p2w的map双向检查映射有没有一一对应
 */
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        unordered_map<char,char> ptow, wtop;
        
        for (int i = 0; i < words.size(); i++)
        {
            int j=0;
            wtop.clear();
            ptow.clear();
            bool flag = true;
            for (j = 0; j < words[i].size(); j++)
            {
                if (!ptow.count(pattern[j]))
                {
                    if (wtop.count(words[i][j])){
                        flag = false;
                        break;
                    }
                    ptow[pattern[j]]=words[i][j];
                    wtop[words[i][j]] = pattern[j];
                }
                else if(wtop[words[i][j]]!=pattern[j])
                {
                    flag = false;
                    break;
                    
                }
            
             }
            if (flag)
            {
                res.push_back(words[i]);
            }
        }
        return res; 
    }
};

