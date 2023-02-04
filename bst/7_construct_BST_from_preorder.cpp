//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

/**
 * Definition for a binary tree node.
 * */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
private:
    TreeNode* solve(vector<int>&preorder, int min, int max, int &i){
        //if i is greater than size 
        if (i >= preorder.size()){
            return NULL;
        }
        //if not in range of min and max 
        if(preorder[i] < min || preorder[i] > max){
            return NULL;
        }
        //can form node 
        TreeNode* root = new TreeNode(preorder[i++]);

        //left and right recursive call 
        root -> left = solve(preorder, min, root->val, i);
        root -> right = solve(preorder, root->val, max, i);
        return root; 
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //Optimized Approach using min and max 
        int min = INT_MIN;
        int max = INT_MAX; 
        int i = 0; 
        TreeNode* root = solve(preorder, min, max, i);
        return root;
    }
};