#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

/*
Step1: put root element in stack first and print it 
Step2: Pop out element and push its left element to stack and keep on pushing each left element to its left till you reach NULL 
Step3: If you encounter NULL, pop out the element and print it 
and push its right element to stack  
*/
vector<int> iterative_inorder(Node* root){
    vector<int>ans; 
    if(!root){
        return ans;
    }
    stack<Node*> st; 
    Node* node = root;
    while (true){
        if (node){
            st.push(node);
            node = node -> left;
        } else {
            if (st.empty()){
                break;
            }
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node -> right; 
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1, new Node(2, new Node(3), new Node(4, new Node(5), new Node(6))), new Node(7));
    vector<int>inorder = iterative_inorder(root);
    for(int i = 0; i < inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout << endl;
}