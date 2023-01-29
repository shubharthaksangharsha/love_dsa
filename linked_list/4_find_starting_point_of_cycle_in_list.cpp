//https://www.codingninjas.com/codestudio/problems/detect-the-first-node-of-the-loop_1112628

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

*
****************************************************************/

Node* getPoint(Node* &head){
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
Node* getStartingPoint(Node* head){
    Node* fast = getPoint(head);
    if (fast == NULL){
        return NULL;
    }
    Node* slow = head;
    while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}
Node *firstNode(Node *head)
{
	if(!head || ! head-> next){
        return NULL;
    }
    return getStartingPoint(head);
}