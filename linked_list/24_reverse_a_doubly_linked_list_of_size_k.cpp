//https://www.codingninjas.com/codestudio/problems/reverse-dll-nodes-in-groups_920399?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this ->data = data;
        }
};
Node* reverseDLLInGroups(Node* head, int k)
{	
	//base case 
	if(!head){
		return NULL;
	}
    int count = 0; 
	Node* prev = NULL;
	Node* curr = head;
	Node* forward = NULL;
	while(curr && count < k){
		forward = curr->next;
		curr->next = prev; 
		curr->prev = forward; 
		prev = curr;
		curr = forward;
		count++;
	}
	//Step2: recursion sambhalega 
	if(forward){
		head->next = reverseDLLInGroups(forward, k);
	}
	//Step3: return prev 
	return prev; 
}