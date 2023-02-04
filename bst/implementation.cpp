//Author: Shubharthak Sangharasha
/*  Date: 2023-02-01 13:20:54
         Description: Implementation of Binary Search Tree
*/

#include<bits/stdc++.h>
using namespace std;

// template<typename T>
class Node{
    public: 
        // T data; 
        int data;
        Node* left; 
        Node* right;
        //Default Constructor
        Node(){
            // this ->data = 0;
            this ->data = 0;
            this -> left = NULL;
            this -> right = NULL;
        }

        //Parametized Constructor 
        // Node(T data){
        Node(int data){
            this ->data = data; 
            this->left = NULL;
            this -> right = NULL;
        }
        // Node(T data, Node* left, Node* right){
        Node(int data, Node* left, Node* right){
            this ->data = data;
            this->left = left;
            this->right = right;
        }
};
void insert_in_bst(Node* &root, int data){
    //base case 
    if(!root){
        root = new Node(data);
        return;
    }
    if (data > root->data){
        insert_in_bst(root->right, data);
    } else {
        insert_in_bst(root->left, data);
    }
}

void inorder(Node* root){
    if (!root){
        return;
    }
    inorder(root->left);
    cout << root -> data << " ";
    inorder(root->right);
}
void preorder(Node* root){
    if (!root){
        return;
    }
    cout << root -> data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if (!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root -> data << " ";
}

void takeInput(Node* &root){
    int data; 
    cin >> data; 
    while(data != -1){
        insert_in_bst(root, data);
        cin >> data;
    }
}
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        } else{
            cout << node -> data << "->";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
}
int minValue(Node* root) {
    if(root == NULL){
        return -1;
    }
    Node* temp = root;
    while(temp->left ){
        temp = temp -> left;
    }
    return temp->data;
}

int maxValue(Node* root) {
    if(root == NULL){
        return -1;
    }
    Node* temp = root;
    while(temp->right ){
        temp = temp -> right;
    }
    return temp->data;
}


Node* deletefromBST(Node* root, int val){
    //base case 
    if(!root){
        return NULL;
    }
    if (root -> data == val){
        //0 child 
        if(root->left == NULL && root->right == NULL){
            delete root; 
            return NULL;
        }
        //1 child 
        if (!root->right || !root->left){
            return root->left ? root->left: root->right;
        }
        //2 child 
        // Node* temp = root->left;
        // while(temp->right){
        //     temp = temp->right;
        // }
        root->data = maxValue(root->left);
        root->left = deletefromBST(root->left, root->data);
        return root;
    }
    if(root->data < val){
        root ->right = deletefromBST(root->right, val);
        return root;
    } 
    root->left = deletefromBST(root->left, val);
    return root;
}
int main(){
    Node* root = NULL;
    cout << "Enter data to create BST" << endl;
    takeInput(root);
    cout << "Printing Level Order" << endl;
    levelOrderTraversal(root);

    cout << "Printing Preorder: ";
    preorder(root);
    cout << endl;
    
    cout << "Printing Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Printing Postorder: ";
    postorder(root);
    cout << endl;
    int key;
    cout << "Enter key you want to delete from BST: ";
    cin >> key;
    root = deletefromBST(root, key);

    cout << "Printing Level Order" << endl;
    levelOrderTraversal(root);

    cout << "Printing Preorder: ";
    preorder(root);
    cout << endl;
    
    cout << "Printing Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Printing Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}