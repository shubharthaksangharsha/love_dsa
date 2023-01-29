//https://practice.geeksforgeeks.org/problems/circular-linked-list/1

bool checkCircular(Node* head){
   if (!head){
       return true;
   }
   
   Node* temp = head -> next;
   while(temp && temp != head){
       temp = temp->next;
   }
   return head == temp; 
}
/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   //tortoise hare approach 
   Node* slow = head; 
   Node* fast = head -> next; 
   
   while(fast && fast ->next){
       if (slow == fast){
           return true;
       }
       fast = fast ->next -> next;
       slow = slow -> next;
   }
   return false;
}