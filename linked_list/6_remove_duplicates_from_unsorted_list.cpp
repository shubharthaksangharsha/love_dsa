//https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

class Solution
{   

    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        if (!head || !head -> next){
            return head;
        }
        map<int*, bool>mp;
        Node* temp = head;
        Node* prev = NULL;
        while(temp){
            if (mp[temp -> data]){
                Node* delete_node = temp;
                prev -> next = temp -> next;
                delete delete_node;
                temp = prev -> next;
                
            } else { 
                mp[temp -> data] = true;
                prev = temp;
                temp = temp -> next;
            }
        }
        return head;
    }
};