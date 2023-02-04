#include<iostream>
using namespace std;

class node{
public:
int data;
node *next;
node(int data){
    this-> data = data;
    this-> next = NULL;

}

~node(){
    int value = this-> data;
    if(this->next != NULL){
        delete next;
        this-> next = NULL;
    }
    cout<< "Memory is free for node with data "<< value<<endl; 
}
};
    void insertAtHead(node* &head, int data){
    node *temp = new node(data);
    temp-> next = head;
    head = temp;
    
}
    void insertAtTail(node* &tail, int data){
        node* temp = new node(data);
        tail->next = temp;
        tail = temp;
    }
    void insertAtPosition(node* &tail, node* &head, int position, int d ){
    node * temp = head;
    int cnt = 1;
    if(position ==1){
        insertAtHead(head,d);
        return;
    }
    while(cnt< position-1){
         temp = temp->next;
         cnt++;
    }

    if(temp->next ==NULL){
        insertAtTail(tail, d);
        return;
    }
    node * nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    }

    void deleteNode( int position, node * &head, node* &tail ){
         if(position == 1){

            node *temp = head;
            head = head-> next;
            temp->next = NULL;
            delete temp;

         }
         
         else{
            node *curr = head;
            node *prev = NULL;
            int cnt = 1;
            while(cnt< position){
                prev = curr;
                curr = curr-> next;
                
                cnt++;
            }
                    //  prev
            //1 2 3 4 5-> 6
            /*
            position = 6 
            count  = 1

            */
           if(curr ->next == NULL){
            tail = prev;
            tail -> next = NULL;
            delete curr;
           }
          else{
            
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
          }
         }
    }


    void print(node* &head){

    node *temp = head;
    while(temp != NULL){
        cout<< temp->data<< " ";
        temp = temp->next; 

    }
    cout<<endl;
    }

   /* void reverseLinkedList(node* &head){
        node * curr = head;
        node * prev = NULL;
        node * forward = NULL;
        while(curr!= NULL){
            forward = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = forward;

        }
    }
    */

int main(){
    node *node1 = new node(10);
    //cout<< node1 -> data<<endl;
    //cout<< node1 -> next<<endl;
    node *tail = node1;
    node *head = node1;
    cout<<endl;
    insertAtHead(head, 11);
    print(head);

    insertAtTail( tail, 15);
    print(head);

    insertAtTail( tail, 12);
    print(head);

    insertAtPosition(tail, head, 1, 13);
    print(head);

    insertAtPosition(tail, head, 3, 16);
    print(head);

    deleteNode(6, head, tail);
    print(head);

    cout<< "head "<< head->data<<endl;
    cout<< "tail "<< tail->data<<endl;
    
}