//https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

class Solution {
  private:
  int solve(Node* root, int& i, int k){
      //base case 
      if(!root){
          return -1;
      }
      //L
      int left = solve(root->left, i, k);
      if(left != -1){
          return left;
      }
      //N
      i++;
      if(i == k){
          return root->data;
      }
      //R
      int right = solve(root->right, i, k);
      if(right!= -1){
          return right;
      }
      return -1;
  }
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int i = 0;
        int ans = solve(root, i, K);
        return ans;
    }
};