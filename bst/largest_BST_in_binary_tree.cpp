//https://practice.geeksforgeeks.org/problems/largest-bst/1

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

class info{
    public:
    int maxi; 
    int mini;
    bool isBST; 
    int size;
};
class Solution{
    private:
    info solve(Node* root, int &ans){
        //base case
        if(!root){
            return {INT_MIN, INT_MAX, true, 0};
        }
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        info currNode; 
        currNode.size = left.size + right.size + 1;
        currNode.maxi = max(root->data, right.maxi);
        currNode.mini = min(root->data, left.mini);
        if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
            currNode.isBST = true;
        } else{
            currNode.isBST = false;
        }
        //ans update 
        if(currNode.isBST){
            ans = max(ans, currNode.size);
        }
        return currNode;
        
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	int maxSize = 0; 
    	info temp  = solve(root, maxSize);
    	return maxSize;
    }
};