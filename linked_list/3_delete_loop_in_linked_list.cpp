//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
//Author: Shubharthak Sangharasha
/*  Date: 2023-01-25 23:51:34
         Description:
*/
#include<bits/stdc++.h>
#include "link.cpp"
using namespace std;

class Solution
{
    private:
        Node* getLoop(Node* head){
            Node* slow = head;
            Node* fast = head;
            while(fast && fast -> next){
                fast = fast -> next -> next;
                slow = slow -> next;
                if(slow == fast){
                    return slow;
                }
            }
            return NULL;
        }
        Node* getStart(Node* fast, Node* head){
            Node* slow = head;
            while(fast != slow){
                slow = slow -> next;
                fast = fast -> next;
            }
            return fast;
        }
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if (!head){
            return;
        }
        
        //Get loop 
        Node* fast = getLoop(head);
        if (fast == NULL){
            return;
        }
        
        fast = getStart(fast, head);
        Node* temp = fast;
        while(temp->next != fast){
            temp = temp -> next;
        }
        temp -> next = NULL;
        
    }
};
/*
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

****************************************************************

Node* getCycle(Node* head){
	//Tortoise-Hare Approach 
	if(!head && !head ->next){
		return NULL;
	}
	
	Node* slow = head;
	Node* fast = head; 
	while(fast && fast -> next){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow){
			return slow;
		}
	}
	return NULL;
}

Node* getFirst(Node* fast, Node* head){
	Node* slow = head; 
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

bool detectAndRemoveCycle(Node* head)
{
	if(!head || !head->next){
		return false;
	}
	Node* fast = getCycle(head);
	if (fast == NULL){
		return false;
	}
	Node* slow = getFirst(fast, head);
	Node* temp = slow;
	while(temp->next){
		temp = temp->next;
	}
	temp ->next = NULL;
	return true;
}

*/
