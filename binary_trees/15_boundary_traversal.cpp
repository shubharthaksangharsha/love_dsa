//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

void traversalLeft(Node* root, vector<int>&ans){
    //base case 
    if (!root ||!root->left && !root->right ){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traversalLeft(root->left, ans);
    } 
    if(root->right){
        traversalLeft(root->right, ans);
    }

}

void traversalLeaf(Node* root, vector<int>&ans){
    //base case 
    if(!root){
        return;
    }
    //leaf node 
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    traversalLeaf(root->left, ans);
    traversalLeaf(root->right,ans);
}

void traverseRight(Node* root, vector<int>&ans){
    //base case 
    if(!root || !root->left && !root->right){
        return;
    }
    if(root->right){
        traverseRight(root->right, ans);
    }
    if(root->left){
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> boundary(Node* root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    //left part print/store
    traversalLeft(root->left, ans);

    //traverse leaf nodes
    
    //left subtree
    traversalLeaf(root->left, ans);
    //right subtree
    traversalLeaf(root->right, ans);

    //right part print/store
    traverseRight(root->right, ans);

    return ans;
}
int main(){
  
    return 0;
}