/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    ListNode* reverse_list(ListNode* head){
        if (!head || !head -> next){
            return head;
        }
        ListNode* chottaHead = reverse_list(head->next);
        head->next->next = head;
        head ->next = NULL;
        return chottaHead;
    }
        // void helper(ListNode* &head, ListNode* curr, ListNode* prev){
        //     if (curr == NULL ){
        //         head = prev; 
        //         return;
        //     }
        //     ListNode* forward = curr -> next; 
        //     helper(head, forward, curr);
        //     curr -> next = prev; 
        // }
public:
    ListNode* reverseList(ListNode* head) {
        //Recursion 2nd method:- 
        head = reverse_list(head);
        return head;
        //recursion 1st method:-
        // ListNode* curr = head;
        // ListNode* prev = NULL;
        // helper(head, curr, prev);
        // return head;

        //Iterative Method:-
        // ListNode* curr = head;
        // ListNode* prev = NULL;
        // while (curr){
        //     ListNode* next_node = curr -> next;
        //     curr -> next = prev;
        //     prev = curr;
        //     curr = next_node;
        // }
        // return prev;
    }
};