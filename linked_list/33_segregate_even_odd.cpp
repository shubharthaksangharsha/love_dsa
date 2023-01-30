//https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

#include<bits/stdc++.h>
#include "link.cpp"
using namespace std;

class Solution{
public:
    Node* divide(int N, Node *head){
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* temp = head; 
        while(temp){
            if (temp->data % 2 == 0){ //even case
                if(!evenStart){ //empty
                    evenStart = temp;
                    evenEnd = evenStart;
                } else { 
                    evenEnd -> next = temp;
                    evenEnd = evenEnd -> next;
                 }
            } else { 
                //odd case 
                if(!oddStart){ //empty 
                    oddStart = temp; 
                    oddEnd = oddStart;
                } else {
                    oddEnd -> next = temp;
                    oddEnd = oddEnd -> next;
                }
            }
            temp = temp -> next;
        }
        if(!oddStart || !evenStart) {return head;} 
        evenEnd -> next = oddStart; 
        oddEnd -> next = NULL;
        return evenStart;
    }
};