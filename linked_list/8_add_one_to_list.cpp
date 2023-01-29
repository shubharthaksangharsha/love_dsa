//https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

class Solution
{
    private:
        Node* reverse_list(Node* head){
            Node* curr = head;
            Node* prev = NULL;
            while(curr){
                Node* forward = curr -> next;
                curr -> next = prev; 
                prev = curr;
                curr = forward;
            }
            return prev;
        }
    public:
    Node* addOne(Node *head) 
    {
        head = reverse_list(head);
        
        Node* curr = head; 
        int sum = curr -> data + 1; 
        curr -> data = sum % 10;
        int carry = sum / 10; 
        Node* prev = head;  
        curr = head -> next;
        while(curr){
            sum = curr -> data + carry; 
            curr -> data = sum % 10;
            carry = sum / 10;
            prev = curr;
            curr = curr -> next;
        }
        
        if (carry){
            prev -> next = new Node(carry);
        }
        return reverse_list(head);
        
    }
};