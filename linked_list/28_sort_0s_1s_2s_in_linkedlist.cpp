//https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
#include<bits/stdc++.h>
#include "link.cpp"
using namespace std;

class Solution
{
    private:
    void populate(Node* &tail, Node* curr){
        tail -> next = curr; 
        tail = curr; 
    }
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        //Approach1: using data replacement 
        // int zero = 0, ones = 0, two = 0;
        // Node* temp = head; 
        // while(temp){
        //     if (temp->data == 0){
        //         zero++;
        //     } else if (temp->data == 1){
        //         ones++;
        //     } else{
        //         two++;
        //     }
        //     temp = temp -> next;
        // }
        // temp = head; 
        // while(temp){
        //     if(zero){
        //         temp->data = 0;
        //         zero--;
        //     } else if (ones){
        //         temp ->data = 1;
        //         ones--;
        //     } else { 
        //         temp ->data = 2;
        //         two--;
        //     }
        //     temp = temp -> next;
        // }
        // return head;
        
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* curr = head; 
        //seperate linked list 0s, 1s and 2s.
        while(curr){
            int value = curr->data; 
            if(value == 0){
                populate(zeroTail, curr);
            } else if (value == 1){
                populate(oneTail, curr);
            } else if (value == 2){
                populate(twoTail, curr);
            }
            curr = curr -> next;
        }
        
        //merge 
        if(oneHead->next){
            zeroTail->next = oneHead->next;
        } else { 
            zeroTail->next = twoHead->next;
        }
        
        oneTail ->next = twoHead->next;
        twoTail->next = NULL;
        
        //setup head
        head = zeroHead->next;
        
        //delete dummy nodes 
        delete zeroHead;
        delete oneHead;
        delete twoHead; 
        
        return head;
        
    }
};