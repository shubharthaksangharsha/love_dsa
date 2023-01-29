//https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055

#include<bits/stdc++.h>
using namespace std;
template <typename T> class BinaryTreeNode{
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
    
};

// void inorder(BinaryTreeNode<int>* root, int &count){
//     if (!root){
//         return;
//     }
//     inorder(root->left, count);
//     //leaf node condition 
//     if(root ->left == NULL && root -> right == NULL){
//         count++;
//     }
//     inorder(root->right, count);
// }
// int noOfLeafNodes(BinaryTreeNode<int> *root){
//     int count = 0; 
//     inorder(root, count);
//     return count;
// }