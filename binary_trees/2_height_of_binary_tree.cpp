//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
#include<iostream>
using namespace std;


struct Node{
    struct Node* left;
    struct Node* right;
};

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        //base case 
        if(!node){
            return 0;
        }
        int left = height(node -> left);
        int right = height(node -> right);
        int ans = max(left, right) + 1;
        return ans;
    }
};