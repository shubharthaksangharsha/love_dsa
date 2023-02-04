#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;
template<typename T> class TreeNode{
    public:
        T data; 
        TreeNode* left; 
        TreeNode* right;
        TreeNode<T>(T data){
            this->data = data;
        }
};
void inorder(TreeNode<int>* root, vector<int>&inorderVal){
    if (!root){
        return;
    }
    inorder(root->left, inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right, inorderVal);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{   
    vector<int>v;
    inorder(root, v);
    TreeNode<int>*head = new TreeNode<int>(v[0]);
    TreeNode<int>*curr = head;
    for(int i = 1; i < v.size(); i++){
        TreeNode<int>*temp = new TreeNode<int>(v[i]);
        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
    }
    curr -> left = NULL;
    curr -> right = NULL;
    return head;
}