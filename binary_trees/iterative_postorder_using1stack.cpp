#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

/*
Step1: put root element in stack first and print it 
Step2: Pop out element and push its right element and then left element 
Step3: Do it will untill stack is empty 
*/
vector<int> iterative_postorder(Node* root){
    vector<int>ans; 
    if(!root){
        return ans;
    }
    stack<Node*> st; 
    st.push(root);
    Node* curr = root;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr -> left;
        } else {
            auto temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                
            }
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1, new Node(2, new Node(3), new Node(4, new Node(5), new Node(6))), new Node(7));
    vector<int>postorder = iterative_postorder(root);
    for(int i = 0; i < postorder.size(); i++){
        cout << postorder[i] << " ";
    }
    cout << endl;
}