//https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

#include<bits/stdc++.h>
#include "link.cpp"
using namespace std;

class Solution
{
    private:
    Node* reverse_node(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }
    void print(Node *head){
        Node* temp = head;
        while(temp){
            cout << temp->data << "->";
        }
        cout << endl;
    }
    public:
    Node *compute(Node *head)
    {
        head = reverse_node(head);
        Node* curr = head; 
        int ma = head->data;
        Node* prev = head;
        head = head->next;
        while(head){
            if(head->data >= ma){
                ma = head->data; 
                prev = head;
                head = head->next;
            } else{
                prev->next = head->next;
                head = prev->next;
            }
        }
        head = reverse_node(curr);
        return head;
    }
    
};