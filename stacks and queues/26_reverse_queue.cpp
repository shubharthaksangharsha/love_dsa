//https://www.codingninjas.com/codestudio/problems/reversing-queue_1170046?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker

#include <bits/stdc++.h> 
using namespace std; 

void reverse(queue < int > & q) {
    stack<int>st;
    while(q.size()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

void reverse_recursion(queue<int>&q){
    //base case 
    if (q.empty()){
        return;
    }
    int temp = q.front();
    q.pop();
    //recursive call 
    reverse_recursion(q);
    
    q.push(temp);
}
void display(queue<int>&q){
    queue<int>temp = q;
    while(!temp.empty()){
        cout << temp.front() << endl;
        temp.pop();
    }
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    display(q);

    reverse_recursion(q);
    display(q);

}