//https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int>q, int k){
    stack<int>st; 
    int i = 0; 
    while(i < k){
        int temp = q.front();
        st.push(temp);
        q.pop();
        i++;
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    int size = q.size() - k;
    for(int i = 0; i < size; i++){
        q.push(q.front());
        q.pop();
    }

    return q;
}

