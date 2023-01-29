//https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

class Solution
{   
    private:
        void delete_node(Node* &temp, Node* &test){
            while(test -> next){
                if (temp -> data == test -> next -> data){
                    Node* node_delete = test -> next;
                    test -> next = test -> next -> next;
                    delete node_delete;
                } else{
                    test = test -> next;
                }
            }
        }
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        //O(N^2) solution: brute force
        Node* temp = head; 
        while(temp && temp -> next){
            Node* test = temp;
            delete_node(temp, test);
            temp = temp -> next;
        }
        return head;
        //Optimized best solution: O(NlogN)
        // if (!head || !head -> next){
        //     return head;
        // }
        // map<int, bool>mp;
        // Node* temp = head;
        // Node* prev = NULL;
        // while(temp){
        //     if (mp[temp->data]){
        //         Node* delete_node = temp;
        //         prev -> next = temp -> next;
        //         delete delete_node;
        //         temp = prev -> next;
                
        //     } else { 
        //         mp[temp->data] = true;
        //         prev = temp;
        //         temp = temp -> next;
        //     }
        // }
        // return head;
    }
};
