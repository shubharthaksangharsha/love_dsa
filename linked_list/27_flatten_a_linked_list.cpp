//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data; 
        Node* next;
        Node* bottom;
        Node(int data){
            this->data = data;
        }
};
/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node* a, Node* b){
    Node* temp = new Node(0);
    Node* res = temp; 
    while(a && b){
        if(a->data < b->data ){
            temp -> bottom  = a; 
            temp = temp -> bottom;
            a = a -> bottom;
        } else{
            temp -> bottom = b; 
            temp = temp -> bottom;
            b = b -> bottom;
        }
    }
    if(a){
        temp -> bottom = a; 
    }
    if(b){
        temp -> bottom = b;
    }
    return res -> bottom;
}
Node *flatten(Node *root)
{
    //base case 
    if(!root || !root->next){
        return root;
    }
    //recursive for list on right
    root -> next = flatten(root->next);
    //now merge 
    root = merge(root, root->next);
    
    return root;
}
