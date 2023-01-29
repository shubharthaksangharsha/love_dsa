//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int i = 0;
        while(i < s.size()){
            if (st.empty() || st.top() != s[i]){
                st.push(s[i++]);
            } else {
                st.pop();
                i++;
            }
        }

        //if stack is empty return empty string
        if(st.empty()){
            return "";
        } 
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};