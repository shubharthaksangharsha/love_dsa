//https://leetcode.com/problems/rotate-list/
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int val; 
        ListNode* next;
};
class Solution {
private:
    int count(ListNode* head){
        int ans = 0;
        ListNode* temp = head; 
        while(temp){
            ans++;
            temp = temp -> next;
        }
        return ans;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //edge case 
        if(!head || !head->next || k == 0){
            return head;
        }
        //compute length 
        int len = count(head);
        //go till last node 
        ListNode* curr = head; 
        while(curr->next){
            curr = curr->next;
        }
        curr -> next = head; 
        k = k % len; 
        k = len - k; //if right rotate do this else for left rotate skip this line 
        while(k--){
            curr = curr->next;
        }
        //make the node head and break connection 
        head = curr -> next;
        curr ->next = NULL; 
        return head;

    }
};