//Author: Shubharthak Sangharasha
/*  Date: 2023-02-03 21:04:02
         Description: Check Binary Tree is Heap or not?
*/
#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

bool isMaxOrder(Node* root){
    //Leaf node 
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    //Both child exists
    if(root->right == NULL){
        return root->data < root->left->data;  
    } 
    //Only Left child exists
    return root->data > root->left->data && root->data > root->right->data && isMaxOrder(root->left) && isMaxOrder(root->right);  
}

bool isCBT(Node* root, int i, int nodeCount){
    if(root == NULL){
        return true;
    }
    if(i >= nodeCount){
        return false;
    }
    bool left = isCBT(root->left, 2*i + 1, nodeCount);
    bool right = isCBT(root->right, 2* i + 2, nodeCount);
    return left && right; 
}
int countNodes(Node* root){
    int ans = 0; 
    if(root == NULL){
        return 0;
    }
    ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isHeap(Node* root){
    int index = 0;
    int totalCount = countNodes(root);
    if(isCBT(root, index, totalCount) && isMaxOrder(root)){
        return true;
    }
    return false;
}

int main(){
    Node* root = new Node(1, new Node(2), new Node(3));
    cout << isHeap(root) << endl;
    return 0;
}