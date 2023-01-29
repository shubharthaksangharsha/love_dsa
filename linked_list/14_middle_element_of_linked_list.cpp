//https://leetcode.com/problems/middle-of-the-linked-list/description/

class Solution {
private:
    int getLength(ListNode* head){
        int count = 0;
        while(head){
            head = head -> next;
            count++;
        }
        return count;
    }
    ListNode* getmiddle(ListNode* head){
        int length = getLength(head);
        int ans = length / 2; 
        int count = 0; 
        ListNode* temp = head;
        while(count < ans){
            temp = temp -> next;
            count++;
        }
        return temp;
    }

    ListNode* getmiddle_floyd(ListNode* head){
        if(!head || ! head -> next){
            return head;
        }
        if (!head ->next ->next){
            return head->next;
        }
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast){
            fast = fast -> next;
            if(fast){
                fast = fast -> next;
            }
            slow = slow -> next;
        }
        return slow;
    }
public:
    ListNode* middleNode(ListNode* head) {
        //2 pass appraoch: O(N), SC: o(N)
        // return getmiddle(head);

        //1 pass approach(tortoise and hare): O(N), SC: O(n)       
        return getmiddle_floyd(head);
    }
};