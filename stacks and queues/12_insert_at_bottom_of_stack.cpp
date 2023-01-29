//https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

#include <bits/stdc++.h> 
using namespace std; 

void solve(stack<int>&myStack, int x){
    //base case
    if (myStack.empty()){
        myStack.push(x);
        return;
    }
    int temp = myStack.top();
    myStack.pop();
    
    //recursive call 
    solve(myStack, x);
    
    myStack.push(temp);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}
