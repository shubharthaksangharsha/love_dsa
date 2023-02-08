//https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

// Function to find the minimum element in the given BST.
int minValue(Node* root) {
    if(root == NULL){
        return -1;
    }
    Node* temp = root;
    while(temp->left ){
        temp = temp -> left;
    }
    return temp->data;
}
// Function to find the maximum element in the given BST.
int maxValue(Node* root) {
    if(root == NULL){
        return -1;
    }
    Node* temp = root;
    while(temp->right ){
        temp = temp -> right;
    }
    return temp->data;
}

