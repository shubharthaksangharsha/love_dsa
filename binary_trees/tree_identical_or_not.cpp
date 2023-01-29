//https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

#include<iostream>
#include "implementation.cpp"
using namespace std;

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //base case 
        if(!r1 && !r2){
            return true;
        }
        if((!r1 && r2) || (r1 && !r2)){
            return false;
        }
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        
        bool value = r1->data == r2->data; 
        if(left && right && value){
            return true;
        }
        return false;
    }
};