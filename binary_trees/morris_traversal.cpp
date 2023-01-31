//Author: Shubharthak Sangharasha
/*  Date: 2023-01-31 14:31:02
         Description: Morris Inorder and Preorder Traversal 
*/

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

vector<int> getMorrisInorder(Node* root){
    vector<int>inorder; 
    Node* curr = root; 
    while(curr){
        //1st edge case: root have no left so itself it's a root
        //add the current root and move right
        if(!curr->left){
            inorder.push_back(root->data);
            curr = curr->right;
        } else{
            //2nd case: left exists then find precedor and connect to curr 
            Node* precedor = curr->left;
            while(precedor->right && precedor->right != curr){
                precedor = precedor ->right;
            }
            //precedor is null
            if(!precedor->right){
                precedor->right = curr; //threading to curr 
                curr = curr->left; //moving left now
            } else {
                //precedor is already threaded to curr so remove the thread
                precedor-> right = NULL;
                inorder.push_back(curr->data); //add currnode now as left done
                curr = curr->right; //move to right as already visited left
            }

        }
    }
    return inorder;
}
vector<int> getMorrisPreorder(Node* root){
    vector<int>preorder; 
    Node* curr = root; 
    while(curr){
        //1st edge case: root have no left so itself it's a root
        //add the current root and move right
        if(!curr->left){
            preorder.push_back(root->data);
            curr = curr->right;
        } else{
            //2nd case: left exists then find precedor and connect to curr 
            Node* precedor = curr->left;
            while(precedor->right && precedor->right != curr){
                precedor = precedor ->right;
            }
            //precedor is null
            if(!precedor->right){
                precedor->right = curr; //threading to curr 
                preorder.push_back(curr->data); //add currnode now as left done
                curr = curr->left; //moving left now
            } else {
                //precedor is already threaded to curr so remove the thread
                precedor-> right = NULL;
                curr = curr->right; //move to right as already visited left
            }

        }
    }
    return preorder;
}