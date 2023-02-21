//https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

#include<bits/stdc++.h>
#include "link.cpp"
using namespace std;

class Solution{
  private:
    Node* findMid(Node* head){
        Node* slow = head; 
        Node* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node* headA, Node* headB){
        if(!headA){
            return headB;
        }
        if(!headB){
            return headA;
        }
        Node* dummy = new Node(0);
        Node* head = dummy; 
        while(headA && headB){
            if(headA->data < headB->data){
                head->next = headA; 
                head = headA; 
                headA = headA->next;
            } else{
                head->next = headB; 
                head = headB;
                headB = headB->next;
            }
        }
        if(headA){
            head->next = headA;
            head = headA;
        }
        if(headB){
            head->next = headB;
            head = headB;
        }
        return dummy->next;
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        //base case 
        if(!head || !head->next){
            return head; 
        }
        //break linked list into 2 halves, after finding mid
        Node* mid = findMid(head); 
        Node* left = head; 
        Node* right = mid->next;
        mid->next = NULL;
        //recursive calls
        left = mergeSort(left);
        right = mergeSort(right);
        //merge both left and right halves
        Node* result = merge(left, right);
        return result;
    }
};