//https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
void inorder(TreeNode<int>*root, vector<int>&inorderVal){
    if(root == NULL){
        return;
    }
    inorder(root->left, inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right, inorderVal);
}

TreeNode<int>* inordertoBST(int s, int e, vector<int>inorderVal){
    //BASE CASE 
    if(s > e){
        return NULL;
    }
    int mid = (s + e) / 2; 
    TreeNode<int>* root = new TreeNode<int>(inorderVal[mid]);
    root->left = inordertoBST(s, mid -1, inorderVal);
    root->right = inordertoBST(mid + 1, e, inorderVal);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
	vector<int>inorderVal;
    inorder(root, inorderVal);
    return inordertoBST(0, inorderVal.size()-1, inorderVal);
}
