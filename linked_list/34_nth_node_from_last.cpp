//https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
#include<bits/stdc++.h>
#include "link.cpp"
using namespace std;

//Function to get total length of Linked List 
int count(Node* head){
    int ans;
    Node* temp = head; 
    while(temp){
        ans++;
        temp = temp -> next;
    }
    return ans;
}
//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       //Using Length method 
    //   int length = count(head);
    //   if(length < n){
    //       return -1;
           
    //   }
    //   for(int i = 1; i < length - n + 1; i++){
    //       head = head->next;
    //   }
    //   return head->data;
       //2 Pointers Approach 
       Node* fast = head; 
       for(int i = 0; i < n; i++){
           if(!fast){return -1;}
           fast = fast->next;
       }
       Node* slow = head; 
       while(fast){
           fast = fast->next;
           slow = slow->next;
       }
       return slow->data;
}