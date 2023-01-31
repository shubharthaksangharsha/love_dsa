//https://www.codingninjas.com/codestudio/problems/count-triplets_873377?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data; 
        Node* next;
        Node* prev;
};

int countPairs(Node* first, Node* last, int target){
    int count = 0;
    while(first && last && first != last && last->next != first){
        if(first->data + last->data == target){
            count++;
            first = first->next;
            last = last -> prev;
        } else{
            if(first->data + last->data < target ){
                first = first->next;
            } else{
                last = last -> prev;
            }
        }
    }
    return count;
}
int countAllTripletSum(Node *head, int x)
{
    if(!head){
        return 0;
    }
    int count = 0; 
    Node* current = NULL;
    Node* first = NULL;
    Node* last = head;
    while(last->next){
        last = last->next;
    }
    for(current = head; current != NULL; current = current->next){
        first = current->next;
        count += countPairs(first, last, x - current->data );
    }
    return count;
}