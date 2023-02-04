//https://www.codingninjas.com/codestudio/problems/_893049?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
};
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pred = -1;
    int succ = -1;
    
    BinaryTreeNode<int>*temp = root;
    while(temp->data != key){
        if (temp->data < key){
            pred = temp->data;
            temp = temp->right;
        } else{
            succ = temp->data;
            temp = temp->left;
        }
    }
    //pred 
    BinaryTreeNode<int>* leftTree = temp->left;
    while(leftTree){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    //succ
    BinaryTreeNode<int>* rightTree = temp->right;
    while(rightTree){
        succ = rightTree->data;
        rightTree = rightTree -> left;
    }
    return {pred, succ};
}
