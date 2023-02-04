//Author: Shubharthak Sangharasha
/*  Date: 2023-01-25 23:52:06
         Description: Implementation of Binary Trees
*/

/*
Basic Terms 
1. Node - entity(element) that represents a tree 
2. Root - the topmost/bottom node in a tree having no parent
3. Children - Descendant of any node is called child node 
4. Parent - if node contains any sub-node then that node is said to be parent of subnode
5. Siblings - nodes on same hierarchial level under same parent node
6. Ancestor - pick any node and go till root (all the above nodes from picked node are the ancestors of the picked node)
7. Decendant - pick any node and go till down (all the down nodes from the picked node are the decendant of the picked node)
8. Leaf - nodes which have no child/children
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data; 
        Node* left;
        Node* right;
        //Default Constructor
        Node(){
            this -> data = 0;
            this -> left = NULL;
            this -> right= NULL;
        }
        //Parammetized constructor 
        Node(int data){
            this -> data = data; 
            this -> left = NULL;
            this -> right = NULL;
        }

        Node(int data, Node* left, Node* right){
            this -> data = data; 
            this -> left = left; 
            this -> right = right;
        }
};

Node* buildTree(Node* root){
    int data; 
    cout << "Enter the data: ";
    cin >> data; 
    root = new Node(data);

    if (data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data<< endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of" << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

void levelOrder(Node* root){
    queue<Node*>q; 
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if (!q.empty()){ //queue mein element still hai 
                q.push(NULL);
            }
        } else {
            cout << temp -> data << " ";
            if (temp -> left){
            q.push(temp->left);
            } 
            if(temp -> right){
                q.push(temp->right);
            }
        }
        
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

void buildfromLevelOrder(Node* &root){
    queue<Node*>q; 
    int data; 
    cout << "Enter data for root: ";
    cin >> data; 
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << "Enter left node for " << temp->data << endl;
        int leftdata; 
        cin >> leftdata;
        if(leftdata != -1){
            temp -> left  = new Node(leftdata);
            q.push(temp->left);
        }
        
        cout << "Enter right node for " << temp->data << endl;
        int rightdata; 
        cin >> rightdata;
        if(rightdata != -1){
            temp -> right  = new Node(rightdata);
            q.push(temp->right);
        }

    }
}

vector<int> getMorrisInorder(Node* root){
    vector<int>inorder; 
    Node* curr = root; 
    while(curr){
        //1st edge case: root have no left so itself it's a root
        //add the current root and move right
        if(!curr->left){
            inorder.push_back(root->data);
            curr = curr->right;
        } else{
            //2nd case: left exists then find precedor and connect to curr 
            Node* precedor = curr->left;
            while(precedor->right && precedor->right != curr){
                precedor = precedor ->right;
            }
            //precedor is null
            if(!precedor->right){
                precedor->right = curr; //threading to curr 
                curr = curr->left; //moving left now
            } else {
                //precedor is already threaded to curr so remove the thread
                precedor-> right = NULL;
                inorder.push_back(curr->data); //add currnode now as left done
                curr = curr->right; //move to right as already visited left
            }

        }
    }
    return inorder;
}
vector<int> getMorrisPreorder(Node* root){
    vector<int>preorder; 
    Node* curr = root; 
    while(curr){
        //1st edge case: root have no left so itself it's a root
        //add the current root and move right
        if(!curr->left){
            preorder.push_back(root->data);
            curr = curr->right;
        } else{
            //2nd case: left exists then find precedor and connect to curr 
            Node* precedor = curr->left;
            while(precedor->right && precedor->right != curr){
                precedor = precedor ->right;
            }
            //precedor is null
            if(!precedor->right){
                precedor->right = curr; //threading to curr 
                preorder.push_back(curr->data); //add currnode now as left done
                curr = curr->left; //moving left now
            } else {
                //precedor is already threaded to curr so remove the thread
                precedor-> right = NULL;
                curr = curr->right; //move to right as already visited left
            }

        }
    }
    return preorder;
}
int main(){
    Node* root = NULL;
    // root = buildTree(root);
    buildfromLevelOrder(root);
    levelOrder(root);
    // Node* root = new Node(1, new Node(2), new Node(3));
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order 
    // cout << "\nPrinting level order: " << endl;

    return 0;
}