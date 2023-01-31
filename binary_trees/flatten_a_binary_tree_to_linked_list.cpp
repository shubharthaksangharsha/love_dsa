//https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root; 
        while(curr){
            if(curr->left){
                Node* pred = curr->left; 
                while(pred->right){
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL; // making curr left to NULL
            } 
            curr = curr->right;
        }
    }
};