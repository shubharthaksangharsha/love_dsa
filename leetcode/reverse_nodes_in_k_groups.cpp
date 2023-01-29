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
    int getLength(ListNode* head){
        int size = 0; 
        while(head){
            size++;
            head = head -> next;
        }
        return size;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case 
        if (head == NULL){
            return NULL;
        }

        //Step1: reverse first k groups 
        ListNode* curr = head; 
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        int count = 0; 
        int size = getLength(head);
        if(k <= size){
            while(curr && count < k){
                forward = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forward;
                count++;
            }

            //Step2: recursion sambhalega 
            if (forward){
                head -> next = reverseKGroup(forward, k);
            }
        } else {
            return head;
        }
        
        //Step3: return head of reversed list 
        return prev;    
    }
};