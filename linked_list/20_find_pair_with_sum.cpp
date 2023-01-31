//https://www.codingninjas.com/codestudio/problems/find-pair-with-a-given-sum-in-a-doubly-linked-list_1164172?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0

//Author: Shubharthak Sangharasha
/*  Date: 2023-01-31 20:53:22
         Description:
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data; 
        Node* prev; 
        Node* next;
};

bool findPair(Node* head, int k)
{
    Node* first = head; 
    Node* second = head;
    while(second->next){
        second = second->next;
    }
    while(first != second || second != first){
        if((first->data + second->data) == k){
            return true;
        } else{
            if((first->data + second->data) < k){
                first = first->next;
            } else{
                second = second->prev;
            }
        }
    }
    return false;
}