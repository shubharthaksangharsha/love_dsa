//Author: Shubharthak Sangharasha
/*  Date: 2023-01-21 11:12:05
         Description:
*/
#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int>&st, int num){
    if (st.empty()){
        st.push(num);
        return;
    }
    int temp = st.top();
    st.pop();
    insert_at_bottom(st, num);
    st.push(temp);
}

void reverseStack(stack<int>&st){
    if (st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insert_at_bottom(st, temp);
}

int main(){
    stack<int>st; 
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    stack<int>temp; 
    temp = st; 
    while(temp.size()){
        cout << temp.top() << endl;
        temp.pop();
    }
    cout << endl;
    reverseStack(st);
    while(st.size()){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}   