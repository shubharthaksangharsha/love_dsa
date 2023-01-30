//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

#include<iostream>
#include "link.cpp"
using namespace std;
#include<vector>


class Solution{
  private:
    bool check_pallindrome(vector<int>&ans){
        for(int start = 0, end = ans.size() -1; start <= end; start++, end--){
            if (ans[start] != ans[end]){
                return false;
            }
        }
        return true;
    }
    Node* get_middle(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast && fast->next){
            fast = fast ->next->next;
            slow= slow->next;
        }
        return slow;
    }
    Node* reverse_list(Node* head){
        Node* prev = NULL;
        Node* forward = NULL;
        Node* curr =head;
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // //Normal Solution 
        vector<int>ans;
        Node* temp = head; 
        while(temp){
            ans.push_back(temp->data);
            temp = temp->next;
        }
        bool res = check_pallindrome(ans);
        return res;
        
        //Efficient Solution 
        if(!head || !head->next){
            return true;
        }
        Node* middle = get_middle(head);
        Node* head2 = reverse_list(middle->next);
        while(head2){
            if (head->data != head2->data){
                return false;
            }
            head = head->next;
            head2 = head2 -> next;
        }
        return true;
    }
};