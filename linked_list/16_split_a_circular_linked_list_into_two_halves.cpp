//https://www.codingninjas.com/codestudio/problems/split-a-circular-linked-list_1071003?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker
#include<bits/stdc++.h>
#include "link.cpp"
using namespace std;

Node* getMid(Node* head){
    Node* slow = head; 
    Node* fast = head->next;
    while(fast!=head && fast ->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void splitCircularList(Node *head)
{
    //edge case 
    if(!head || !head->next){
        return;
    }
    Node* mid = getMid(head);
    Node* head2 = mid->next;
    Node* temp = head2; 
    while(temp->next != head){
        temp = temp ->next;
    } 
    temp->next = head2; 
    mid->next = head; 

}
