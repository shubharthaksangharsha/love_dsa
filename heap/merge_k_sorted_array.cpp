//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker

#include <bits/stdc++.h> 
using namespace std; 

class node{
    public:
        int data; 
        int i; 
        int j; 
        node(int d, int i, int j){
            this -> data = d; 
            this -> i = i;
            this -> j = j;
        }
};
class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare>pq; 

    //step1: saare arrays ke first element insert krne hai 
    for(int i = 0; i < k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        pq.push(temp);
    }
    vector<int>ans;
    //step2: 
    while(pq.size() > 0){
        node* temp = pq.top();
        ans.push_back(temp->data);
        pq.pop();
        int i = temp->i;
        int j = temp->j;
        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1], i, j+1);
            pq.push(next);
        }
    }
    return ans;
}
