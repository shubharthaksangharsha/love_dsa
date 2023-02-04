//https://www.codingninjas.com/codestudio/problems/find-a-value-in-bst_1170063?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

template<typename T> class TreeNode{
    public:
        T data ;
        TreeNode* left; 
        TreeNode* right;
};


bool findNode(TreeNode <int> * root, int key) {
    //Recursive way 
    // if(!root){
    //     return false;
    // }
    // if (root->data == key){
    //     return true;
    // }
    // if (root->data < key){
    //     findNode(root->right, key);
    // } else{
    //     findNode(root->left, key);
    // }
    
    //Iterative 
    TreeNode<int>* temp = root;
    while(temp){
        if (temp->data == key){
            return true;
        } else if (temp->data < key){
            temp = temp->right;
        } else{
            temp = temp -> left;
        }
    }
    return false;
}