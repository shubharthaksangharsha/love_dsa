//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275


#include <bits/stdc++.h> 
using namespace std; 

void sortedPush(stack<int>&stack, int temp){
    if (stack.empty() || (!stack.empty() && stack.top() < temp)){
        stack.push(temp);
        return;
    }
    int num = stack.top();
    stack.pop();
    
    sortedPush(stack, temp);
    
    stack.push(num);
}
void sortStack(stack<int> &stack)
{
	if (stack.empty()){
        return;
    }
    int temp = stack.top();
    stack.pop();
    
    //recursive call 
    sortStack(stack);
    
    //push element in sorted manner
    sortedPush(stack, temp);
}