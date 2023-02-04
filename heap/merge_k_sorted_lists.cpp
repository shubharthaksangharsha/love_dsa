//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the linked list node structure

************************************************************/    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

Node<int>* merge(Node<int>* first, Node<int>*second){
    if(!first){
        return second;
    }
    if(!second){
        return first;
    }
    Node<int>*dummy = new Node<int>(0);
    Node<int>*temp = dummy;
    while(first && second){
        if (first->data < second->data){
            temp ->next = first; 
            temp = temp -> next;
            first = first->next;
        } else{
            temp ->next = second;
            temp = temp->next;
            second = second->next;
        }
    }
    if(first){
        temp->next = first;
        temp = temp->next;
    }
    if (second){
        temp ->next = second;
        temp = temp -> next;
    }
    return dummy->next;
}
class compare{
    public:
        bool operator()(Node<int>* a, Node<int>*b){
            return a->data > b->data; 
        }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    if(listArray.size() == 0){
        return NULL;
    }
    if(listArray.size() == 1){
        return listArray[0];
    }
    //Using heap 
    priority_queue<Node<int>*, vector<Node<int>*>, compare> pq;
    int k = listArray.size();
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    //Step1: 
    for(int i = 0; i < k; i++){
        if(listArray[i] != NULL){
            pq.push(listArray[i]);
        }
    }
    while(pq.size()){
        Node<int>* temp = pq.top();
        pq.pop();

        if(temp -> next){
            pq.push(temp->next);
        }
        if (head == NULL) {
          head = temp;
          tail = temp;
        } else {
          tail->next = temp;
          tail = tail->next;
        }
    }
    return head;
}
    //using native merge function
    // Node<int>* output = listArray[0];
    // for(int i = 1; i < listArray.size(); i++){
    //     output = merge(output, listArray[i]);
    // }
    // return output;
    // vector<int>v; 
    // for(auto i: listArray){
    //     while(i){
    //         v.push_back(i->data);
    //         i = i -> next;
    //     }
    // }
    // if(v.size() == 0){
    //     return NULL;
    // }
    // sort(v.begin(), v.end());
    // Node<int>*head = new Node<int>(v[0]);
    // Node<int>* temp = head;
    // for(int i = 1; i < v.size(); i++){
    //     Node<int>*num = new Node<int>(v[i]);
    //     temp -> next = num;
    //     temp = temp -> next;
    // }
    // return head;
