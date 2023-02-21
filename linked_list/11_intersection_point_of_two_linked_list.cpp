//https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1


#include<bits/stdc++.h>
#include "link.cpp"
using namespace std;

//function to find intersection 
int getIntersection(int d, Node* head1, Node* head2){
    Node* current1 = head1; 
    Node* current2 = head2; 
    
    //move pointer forward 
    for(int i = 0; i < d; i++){
        if(!current1){
            return -1;
        }
        current1 = current1->next;
    }
    
    //move both pointers of both list till they intersect with each other 
    while(current1 && current2){
        if(current1 == current2){
            return current1->data;
        }
        //move both pointer forward 
        current1 = current1->next;
        current2 = current2->next;
    }
    return -1;
}
int getCount(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    //O(N^2) approach 
    // while(head2){
    //     Node* temp = head1;
    //     while(temp){
    //         if (temp == head2){
    //             return temp->data;
    //         }
    //         temp = temp ->next;
    //     }
    //     head2 = head2->next;
    // }
    // return -1;
    
    //O(N) approach mark visited using Extra space
    // unordered_set<Node*>st;
    // while(head1){
    //     st.insert(head1);
    //     head1 = head1->next;
    // }
    // while(head2){
    //     if (st.find(head2) != st.end()){
    //         return head2->data;
    //     }
    //     st.insert(head2);
    //     head2 = head2->next;
    // }
    // return -1;
    
    //O(N) approach with constant space (Diiference in node counts)
    // int c1 = getCount(head1);
    // int c2 = getCount(head2);
    
    // int d; 
    // if(c1 > c2){
    //     d = c1 - c2;
    //     return getIntersection(d, head1, head2);
    // } else{
    //     d = c2 - c1;
    //     return getIntersection(d, head2, head1);
    // }

    //More consized and best solution 
    if(!head1 || !head2){
        return -1;
    }
    Node* a = head1; 
    Node* b = head2; 
    while(a != b){
        a = a == NULL ? head2 : a -> next;
        b = b == NULL ? head1 : b -> next;
    }
    return a->data;
}