//https://practice.geeksforgeeks.org/problems/k-sum-paths/1

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

class Solution{
  private:
    void solve(Node* root, int k, int &count, vector<int>path){
        //base case 
        if(!root){
            return;
        }
        path.push_back(root->data);
        //left call 
        solve(root->left, k, count, path);
        //right call 
        solve(root->right, k, count, path);
        //check for K sum 
        int sum = 0;
        for(int i = path.size() -1; i>=0; i--){
            sum += path[i];
            if(sum == k){
                count++;
            }
        }
        path.pop_back();
    }
  public:
    int sumK(Node *root,int k)
    {
        vector<int>path;
        int count = 0; 
        solve(root, k, count, path);
        return count;
    }
}; 