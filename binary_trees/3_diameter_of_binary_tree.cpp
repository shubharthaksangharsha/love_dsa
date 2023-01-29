//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

//longest path between any 2 end nodes(leaf/root).
#include<iostream>
#include "implementation.cpp"
using namespace std;
class Solution {
  private:
    int height(Node* root){
        if (root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }
  public:
    //Function to get diameter+height of a Binary Tree. 
    pair<int, int> diameter_fast(Node* root){
        if (root == NULL){
            pair<int, int>temp = make_pair(0, 0);
            return temp;
        }    
        pair<int, int> left = diameter_fast(root->left);
        pair<int, int> right = diameter_fast(root->right);
        
        int op1 = left.first;
        int op2 = right.first; 
        int op3 = (left.second + right.second) + 1;
        pair<int, int> ans; 
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1; 
        return ans;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        //Naive Solution: O(N^2)
        // //base case
        // if(!root){
        //     return 0;
        // }
        // int op1 = diameter(root->left);
        // int op2 = diameter(root->right);
        // int op3 = height(root->left) + height(root->right) + 1;
        
        // int ans = max(op1, max(op2, op3));
        // return ans;
        
        //Optimized solution: O(N)
        return diameter_fast(root).first;
    }
};