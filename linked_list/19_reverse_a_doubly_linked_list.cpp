//https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include<bits/stdc++.h>
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
Node* reverseDLL(Node * head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(curr){
        forward = curr->next;
        curr->next = prev; 
        curr->prev = forward;
        prev = curr;
        curr = forward;
    }
    return prev;
    
}