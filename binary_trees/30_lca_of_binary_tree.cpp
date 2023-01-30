//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //base case 
       if(!root){
           return NULL;
       }
       if(root->data == n1 || root->data == n2){
           return root;
       }
       
       Node* leftAns = lca(root->left, n1, n2);
       Node* rightAns = lca(root->right, n1, n2);
       
       if(leftAns && rightAns){
           return root;
       } else if (leftAns && !rightAns){
           return leftAns;
       } else if(!leftAns && rightAns){
           return rightAns;
       }
       return NULL;
    }
};