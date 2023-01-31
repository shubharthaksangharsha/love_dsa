//https://leetcode.com/problems/odd-even-linked-list/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
private:
    void populate(ListNode* &head, ListNode* &tail, ListNode* curr){
        if(!head){
            head = curr;
            tail = curr;
            return;
        }
        tail->next = curr;
        tail = tail->next;
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        //edge case 
        if(!head){ //empty
            return NULL;
        }
        if(!head->next || !head->next->next){ //one or two nodes 
            return head;
        }
        ListNode* oddh = NULL;
        ListNode* evenh = NULL;
        ListNode* oddt = NULL;
        ListNode* event = NULL;
        int count = 1; 
        while(head){
            if(count % 2 == 0){
                populate(evenh, event, head);
            } else {
                populate(oddh, oddt, head);
            }
            head = head -> next;
            count++;
        }
        if (!oddh){
            return evenh;
        }
        if(!evenh){
            return oddh;
        }
        event ->next = NULL;
        oddt -> next = evenh;
        return oddh;
    }
};