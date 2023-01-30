//https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

vector<int> diagonal(Node *root)
{
   vector<int>ans;
   if(!root){return ans;}
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty()){
       Node* frontNode = q.front();
       q.pop();
       while(frontNode){
           if (frontNode->left){
               q.push(frontNode->left);
           }
           ans.push_back(frontNode->data);
           frontNode = frontNode->right;
       }
   }
   return ans;
}