//https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

#include<bits/stdc++.h>
#include "link.cpp"
using namespace std;

class Solution{
  private:
    // void print(const vector<int>ivec){
    //     for(auto const i: ivec){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    Node* merge(Node* one, Node* second){
        if(!one){
            return second;
        }
        if(!second){
            return one;
        }
        Node* head = NULL;
        Node* temp = NULL;
        if(one ->data < second->data){
            head = one;
            one = one -> next;
        } else{
            head = second;
            second = second->next;
        }
        temp = head;
        while(one && second){
            if(one){
                temp ->next = one;
                one = one->next;
            } else{
                temp ->next = second;
                second = second->next;
            }
            temp = temp->next;
        }
        if(one){
            temp -> next = one;
        }
        if(second){
            temp ->next = second;
        }
        return head;
    }
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        //using native merge function 
        Node* head = NULL;
        
        for(int i = 0; i < K; i++){
            Node* temp = arr[i];
            head = merge(head, temp);
        }
        return head;
    }
        //   //TC: N log N 
        //   if (K == 0){
        //       return NULL;
        //   }
        //   if(K == 1){
        //       return arr[0];
        //   }
        //   //using vector 
        //   vector<int>v;
        //   for(auto i: arr){
        //       if (i){
        //           v.push_back(i->data);
        //           i = i->next;
        //       }
        //   }
        //   for(int i = 0; i < K; i++){
        //       Node* temp = arr[i];
        //       if(temp){
        //           v.push_back(temp->data);
        //           temp = temp -> next;
        //       }
        //   }
        //   print(v);       
        //   if (v.size() == 0){
        //       return NULL;
        //   }
        //   sort(v.begin(), v.end());
        //   Node* ans = new Node(v[0]);
        //   Node* temp = ans; 
        //   for(int i = 1; i < v.size(); i++){
        //       int data = v[i];
        //       Node* new_node = new Node(data);
        //       temp -> next = new_node;
        //       temp = temp -> next;
        //   }
        //   return ans;
};