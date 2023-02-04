//https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631?leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
        T data; 
        BinaryTreeNode* left; 
        BinaryTreeNode* right;
     
};
void inorder(BinaryTreeNode<int>*root, vector<int>&inorderVal){
    if(root == NULL){
        return;
    }
    inorder(root->left, inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right, inorderVal);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int>inorderVal;
    inorder(root, inorderVal);
    int i = 0, j = inorderVal.size() - 1; 
    while(i < j){
        int sum = inorderVal[i] + inorderVal[j];
        if (sum == target){
            return true;
        } else if(sum < target){
            i++;
        } else{
            j--;
        }
    }
    return false;
}