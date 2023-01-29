//https://practice.geeksforgeeks.org/problems/sum-tree/1

#include<iostream>
#include "implementation.cpp"
using namespace std;

// Should return true if tree is Sum Tree, else false
class Solution
{   
    private:
    pair<bool, int> isSumTreeFast(Node* root){
        //base case 
        if(!root){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        //leaf node base case
        if (!root->left && !root->right){
            pair<bool, int>p = make_pair(true, root->data);
            return p;
        }
        pair<bool, int>leftAns = isSumTreeFast(root->left);
        pair<bool, int>rightAns = isSumTreeFast(root->right);
        
        bool left = leftAns.first; 
        bool right = rightAns.first; 
        
        bool condition = root->data == leftAns.second + rightAns.second; 
        pair<bool, int>ans; 
        if(left && right && condition){
            ans.first = true;
            ans.second = root->data  + leftAns.second + rightAns.second;
            return ans;
        }
        ans.first = false;
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};