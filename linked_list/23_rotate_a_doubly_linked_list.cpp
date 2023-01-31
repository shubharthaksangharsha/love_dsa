//https://www.codingninjas.com/codestudio/problems/rotate-dll_1115782?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0

#include <bits/stdc++.h> 
#include<link.cpp>
/****************************************************

    Following is the class structure of the DLLNode class:
*****************************************************/
    class DLLNode {
    public:
	int data;
	Node *next;
    Node *prev;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};


int count(DLLNode* head){
	DLLNode* temp = head;
	int ans = 0;
	while(temp){
		ans++;
		temp = temp->next;
	}
	return ans;
}
DLLNode* rotateDLL(DLLNode* head, int k) 
{
	if(!head || !head->next || k == 0){
		return head;
	}
	int len = count(head);
    DLLNode* temp = head; 
	while(temp->next){
		temp = temp -> next;
	}
	temp->next = head;
	head->prev = temp;
	k = k % len;
	// k = len - k; 
	while(k--){
		temp = temp -> next;
	}
	head = temp -> next; 
	temp ->next = NULL;
	head->prev = NULL;
	return head;

}