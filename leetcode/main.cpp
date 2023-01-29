//Author: Shubharthak Sangharasha
/*  Date: 2023-01-16 16:24:17
         Description: Removing Duplicates from unsorted list 
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// The structure of linked list is the following

// struct Node {
//   int data;
//   struct Node *next;
//   Node(int x) {
//     data = x;
//     next = NULL;
//   }
// };
// */


class Solution
{   

    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        if (!head || !head -> next){
            return head;
        }
        map<Node*, bool>mp;
        Node* temp = head;
        Node* prev = NULL;
        while(temp && temp -> next){
            if (mp[temp]){
                Node* delete_node = temp;
                prev -> next = temp -> next;
                delete delete_node;
                temp = prev -> next;
            } else { 
                mp[temp] = true;
                prev = temp;
                temp = temp -> next;
            }
        }
        return head;
    }
};
