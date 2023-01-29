//https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        ListNode* next;
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA; 
        ListNode* temp2 = headB;
        unordered_set<ListNode*>st;
        while(temp1){
            st.insert(temp1);
            temp1 = temp1->next;
        }

        while(temp2){
            if (st.find(temp2) != st.end()){
                return temp2;
            }
            st.insert(temp2);
            temp2  = temp2 ->next;
        }
        return NULL;
    }
};