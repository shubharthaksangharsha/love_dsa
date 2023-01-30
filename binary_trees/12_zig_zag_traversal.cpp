//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;
vector<int> zigZagTraversal(Node* root){
    vector<int>ans;
    if(!root){
        return ans;
    }
    queue<Node*>q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int>temp(size);
        //Level Process 
        for(int i = 0; i < size; i++){
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> data;

            if(frontNode->left){
                q.push(frontNode->left);
            }

            if(frontNode ->right){
                q.push(frontNode->right);
            } 
            leftToRight = !leftToRight;
            for(auto i : temp){
                ans.push_back(i);
            }
        }       
    }
    return ans;
}
int main(){
  
    return 0;
}