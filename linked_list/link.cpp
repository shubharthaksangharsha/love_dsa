//Author: Shubharthak Sangharasha
/*  Date: 
         Description:
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

int main(){
    Node* head = new Node();
    Node* head2 = new Node(2);
    cout << head -> data << endl;    
    head -> next = head2;
    cout << head -> next -> data << endl;
    return 0;
}