https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        Node* temp = new Node(data);
        if (!head){
            return temp;
        } 
        if (data < head->data){
            temp->next = head; 
            head = temp;
            return head;
        }
        Node* curr = head;
        while(curr -> next && curr->next->data < data){
            curr = curr -> next;
        }
        temp -> next = curr->next; 
        curr -> next = temp; 
        return head;
    }
};
