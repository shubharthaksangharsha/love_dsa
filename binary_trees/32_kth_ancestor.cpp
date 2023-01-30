//https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

Node* solve(Node* root, int &k, int node){
    //base case 
    if(!root){
        return NULL;
    }
    if(root->data == node){
        return root;
    }
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k , node);
    
    //wapas aunga 
    if (leftAns && !rightAns){
        k--; 
        if(k <= 0){
            k = INT_MAX; //ans locked
            return root; 
        }
        return leftAns;
    }
    if (!leftAns && rightAns){
        k--; 
        if(k <= 0){
            k = INT_MAX; 
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node){
        return -1;
    }
    return ans->data;
}