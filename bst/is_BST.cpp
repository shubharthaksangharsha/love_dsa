//https://practice.geeksforgeeks.org/problems/check-for-bst/1

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;
class Solution
{
    private:
    bool isBST(Node* root, int min, int max){
        //base case 
        if (!root){
            return true;
        }
        if(root->data >= min && root->data  <= max){
            bool left = isBST(root->left, min, root->data);
            bool right = isBST(root->right, root->data, max);
            return left && right;
        } else{
            return false;
        }
    }
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        return isBST(root, INT_MIN, INT_MAX);
    }
};