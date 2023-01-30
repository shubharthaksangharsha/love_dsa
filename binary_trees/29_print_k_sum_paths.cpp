//https://www.codingninjas.com/codestudio/problems/k-sum-path-in-a-binary-tree_893543?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure.
*************************************************************/    
template<typename T> class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
    
            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }
};
    


void solve(BinaryTreeNode<int>* root, int k,vector<int>path, vector<vector<int> >&ans){
    //base case 
    if(!root){
        return;
    }
    //add to path 
    path.push_back(root->data);
    //left child exists 
    if(root->left){
        solve(root->left, k,path, ans);
    }
    //right child exists 
    if(root->right){
        solve(root->right, k,path, ans);
    }
    int sum = 0; 
    for(int i = path.size() -1 ; i >= 0; i--){
        sum += path[i];
        if(sum == k){
            vector<int>temp;
            // cout << "Path Exist: ";
            for(int j = i; j < path.size(); j++){
                // cout << path[j] << " ";
                temp.push_back(path[j]);
            }
            // cout << endl;
            ans.push_back(temp);
        }

    }
    path.pop_back();
}
vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
    vector<vector<int> >ans;
    vector<int>path;
    solve(root, k,path, ans);
    return ans;
}
