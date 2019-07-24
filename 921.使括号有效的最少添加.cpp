/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 * 
 * 使用栈 遇到（压栈，遇到（尝试pop,要考虑"()))(("这种情况，就cnt最后还要加上栈的大小。
 */
class Solution {
public:
    int minAddToMakeValid(string S) {
        int cnt =0;
        stack<char> st;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i]=='(')
            {
                st.push(S[i]);
            }else if (S[i]==')')
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                {
                    cnt++;
                }
            }
        }
        cnt+=st.size();
        return cnt;
    }
};

