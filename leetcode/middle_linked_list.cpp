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
    int getlength(ListNode* head){
        int length = 0;
        while(head){
            length++;
            head = head -> next;
        }
        return length;
    }
    ListNode* getMiddle(ListNode* head){
        if (!head || !head -> next){
            return head;
        }
        if (head ->next -> next == NULL){
            return head -> next;
        }
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast){
            fast = fast -> next;
            if (fast){
                fast = fast-> next;
            }
            slow = slow -> next;
        }
        return slow;
    }
public:

    ListNode* middleNode(ListNode* head) {
        return getMiddle(head);
        /*
        int length = getlength(head);
        int ans = (length / 2);
        ListNode* temp = head;
        int cnt = 0;
        while(cnt < ans){
            temp = temp -> next;
            cnt++;
        }
        return temp;
        */
    }
};