//https://leetcode.com/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private: 
    bool cycleDetectionWithMap(ListNode* head){
        map<ListNode*, bool>mp;
        ListNode* temp = head;
        while(temp){
            if (mp[temp]){
                return true;
            }
            mp[temp] = true;
            temp = temp -> next;
        }
        return false;
    }

    bool floydCycleDetect(ListNode* head){
        if (!head || ! head->next){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        

        while(slow && fast){
            fast = fast -> next;
            if (fast){
                fast = fast-> next;
            }
            slow = slow -> next;
            if (slow == fast){
                return true;
            }
        }
        return false;
    }

public:
    bool hasCycle(ListNode *head) {
        //With Map 
        // return cycleDetectionWithMap(head);

        //Without Map 
        return floydCycleDetect(head);

    }
};