//https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
#include<bits/stdc++.h>
#include "link.cpp"
using namespace std;

//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    if (!head1){
        return head2;
    }
    if (!head2){
        return head1;
    }
    Node* dummy = new Node(0);
    Node* head = dummy; 
    while(head1 && head2){
        if(head1->data < head2->data){
            head ->next = head1;
            head = head1; 
            head1 = head1->next;
        } else { 
            head -> next = head2;
            head = head2;
            head2 = head2->next;
        }
    }
    if(head1){
        head->next =head1;
        head = head1;
    } 
    if(head2){
        head->next = head2;
        head = head2;
    }
    return dummy->next;
}  