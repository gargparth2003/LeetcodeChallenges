class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(int i=0;i<logs.size();i++)
        {
            if(!st.empty() && logs[i]=="../")
                st.pop();
            else if(logs[i]!="./" && logs[i]!="../")
                st.push(logs[i]);
        }
        return st.size();  
    }
};


// question link-- https://leetcode.com/problems/crawler-log-folder/