//Author: Shubharthak Sangharasha
/*  Date: 
         Description: Singly Linked List 
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    //default constructor
    Node(){
        this -> data = 0;
        this -> next = NULL;
    }
    //parametized constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value  = this -> data;
        //memory free 
        if (this -> next != NULL){
            delete next;
            this->next= NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

class SinglyLinkedList{
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int count = 0;
        void insert_at_head(int data);
        void insert_at_tail(int data);
        void insert_at_end(int data);
        void insert_at_position(int pos, int data);
        void delete_node(int pos);
        void display();
        int size(){return count;}
        bool is_circular(Node* head);
        void reverse_iterative();
};

bool SinglyLinkedList::is_circular(Node* head){
    if (!head){
        return true;
    }
    Node* temp = head -> next;
    while(temp && temp != head){
        temp = temp -> next;
    }
    return true ? temp == head : false;
}

void SinglyLinkedList::insert_at_head(int data){
    Node* new_node = new Node(data);
    if (!head){
        head = new_node;
        tail = head;
        count++;
        return;
    }
    new_node -> next = head;
    head = new_node;
    count++;
}

void SinglyLinkedList::insert_at_tail(int data){
    Node* new_node = new Node(data);
    tail -> next = new_node;
    tail = new_node;
    count++;
}
void SinglyLinkedList::insert_at_position(int pos, int data){
    if(pos <= 0 || pos > count){
        cerr<< "Invalid Position" << endl;
        return;
    } 
    if (pos == 1){
        insert_at_head(data);
        return;
    } 
    if (count == pos - 1){
        insert_at_tail(data);
        return;
    }
    Node* temp = head;
    Node* new_node = new Node(data);
    int cnt = 1; 
    while(cnt < pos - 1){
        temp = temp -> next;
        cnt++;
    }
    new_node ->next = temp->next;
    temp->next = new_node;
    count++;
}
/*
temp
|6| -> |2|-> |1|-> null
head
head = head->next
delete temp;
*/
void SinglyLinkedList::delete_node(int pos){
    count--;
    if (pos == 1){
        if (!head->next){
            head = NULL;
            return;
        }
        Node *temp = head;
        head = head ->next;
        temp -> next = NULL;
        delete temp;
        return;
    } 
    Node* current = head;
    Node* prev = NULL;
    int cnt = 1;
    while (cnt < pos){
        prev = current;
        current = current ->next;
        cnt++;
    }
    prev ->next = current ->next;
    current -> next = NULL;
    delete current;
}
void SinglyLinkedList::insert_at_end(int data){
    Node* new_node = new Node(data);
    Node* temp = head;
    while(temp ->next){
        temp = temp -> next;
    }
    count++;
    temp -> next = new_node;
}
void SinglyLinkedList::display(){
    Node* temp = head;
    while(temp){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << endl;
}

/* 
[100] -> [98] -> [1] -> [3] -> [2] -> NULL
*/

void SinglyLinkedList::reverse_iterative(){
    if (head == NULL || head -> next == NULL){
        return;
    }
    Node* prev = NULL;
    Node* cur = head; 
    while (cur){
        Node* next_node = cur -> next;
        cur -> next = prev; 
        prev = cur; 
        cur = next_node;
    }
    head = prev;
}

int main(){
    SinglyLinkedList list;
    list.insert_at_head(2);
    list.insert_at_tail(3);
    list.insert_at_tail(1);
    cout << "Before: ";
    list.display();
    list.insert_at_position(3, 100);
    cout << "After: ";
    list.display();
    list.delete_node(4);
    list.display();
    list.reverse_iterative();
    list.display();
    cout << list.is_circular(list.head);
    
}
