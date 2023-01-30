//https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data; 
        Node* next; 
        Node* arb;
        Node(int data){
            this->data = data;
        }
};

class Solution
{
    private:
    void populate(Node* &head, Node* &tail, int data){
        Node* new_node = new Node(data);
        if(!head){
            head = new_node;
            tail = new_node;
            return;
        }
        tail ->next = new_node;
        tail = tail->next;
    }
    public:
    Node *copyList(Node *head)
    {
        //Using HashMap TC: O(N),SC: O(N)
        //Step1: create a clone list 
        // Node* cloneHead = NULL; 
        // Node* cloneTail = NULL; 
        
        // Node* temp = head; 
        // while(temp){     
        //     populate(cloneHead, cloneTail, temp->data);
        //     temp = temp->next;
        // }
        // //Step2: Create a map 
        // unordered_map<Node*, Node*>mp; 
        // Node* originalNode = head; 
        // Node* cloneNode = cloneHead;
        // while(originalNode &&  cloneNode){
        //     mp[originalNode] =  cloneNode; 
        //     originalNode = originalNode->next;
        //     cloneNode = cloneNode->next;
        // }
        
        // //Step3: Point Random Pointers 
        // originalNode = head; 
        // cloneNode = cloneHead;
        // while(originalNode){
        //     cloneNode -> arb = mp[originalNode->arb];
        //     originalNode = originalNode->next;
        //     cloneNode = cloneNode->next;
        // }
        // return cloneHead;
        
        //Best Optimized Solution TC: O(N) SC: O(1)
        //Step1: Create a clone list 
        Node* cloneHead = NULL; 
        Node* cloneTail = NULL; 
        Node* temp = head; 
        while(temp){
            populate(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        //Step2: cloneNodes add in between Original List 
        Node* originalNode = head; 
        Node* cloneNode = cloneHead; 
        while(originalNode && cloneNode){
            Node* next = originalNode->next;
            originalNode -> next = cloneNode; 
            originalNode = next; 
            
            next = cloneNode -> next; 
            cloneNode -> next = originalNode; 
            cloneNode = next;
        }
        //Step3: Set Random Pointers 
        temp = head; 
        while(temp){
            if(temp->next){
                temp -> next -> arb = temp->arb ? temp->arb->next: temp->arb;
            }
            temp = temp->next->next;   
        }
        //Step4: Revert Step 2 changes 
        originalNode = head; 
        cloneNode = cloneHead; 
        while(originalNode && cloneNode){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            if(originalNode){
                cloneNode->next = originalNode->next;    
            }
            cloneNode = cloneNode->next;
        }
        //Step5: Return ans; 
        return cloneHead;
    }

};