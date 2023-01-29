//https://www.codingninjas.com/codestudio/problems/deleting-and-adding-the-last-node_1170051

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

*****************************************************************/

Node *delAddLastNode(Node *head){
    //edge case
    if(!head || ! head -> next){
        return head;
    }
	Node* curr = head; 
    Node* prev = NULL;
    while(curr -> next){
        prev = curr; 
        curr = curr -> next;
    }
    prev -> next = NULL;
    curr -> next = head; 
    head = curr; 
    return head;
}