//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

class Solution
{   
    private:
    Node* reverse(Node* head){
        Node* curr =head; 
        Node* prev = NULL;
        Node* forward = NULL;
        while(curr){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        struct Node* head = new Node(-1);
        struct Node* temp = head;
        
        int carry = 0; 
        while(first || second || carry){
            int val1 = 0; 
            if (first){
                val1 = first -> data;
            }
            int val2 = 0;
            if (second){
                val2 = second -> data;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10; 
            struct Node* new_node = new Node(digit);
            temp -> next = new_node;
            temp = temp -> next;
            carry = sum / 10; 
            if (first){
                first = first -> next;    
            }
            if (second){
                second = second -> next;    
            }
        }
        return head -> next;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        
        //add 2 LL 
        Node* ans = add(first, second);
        
        
        //Reverse ans list 
        ans = reverse(ans);
        
        return ans;
    }
};