#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

/*
Step1: put root element in stack first and print it 
Step2: Pop out element and push its right element and then left element 
Step3: Do it will untill stack is empty 
*/
vector<int> iterative_preorder(Node* root){
    vector<int>ans; 
    if(!root){
        return ans;
    }
    stack<Node*> st; 
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right){
            st.push(root->right);
        }
        if(root->left){
            st.push(root->left);
        }

    }
    return ans;
}

int main(){
    Node* root = new Node(1, new Node(2, new Node(3), new Node(4, new Node(5), new Node(6))), new Node(7));
    vector<int>preorder = iterative_preorder(root);
    for(int i = 0; i < preorder.size(); i++){
        cout << preorder[i] << " ";
    }
    cout << endl;
}