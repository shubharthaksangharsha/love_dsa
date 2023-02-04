//https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

/*************************************************************
    
    Following is the Binary Tree node structure:
*************************************************************/
template <typename T>
class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
};


void inorder(TreeNode<int>*root, vector<int>&inord){
    if(!root){
        return;
    }
    inorder(root->left, inord);
    inord.push_back(root->data);
    inorder(root->right, inord);
}
void print(vector<int>v){
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;
}
vector<int> merge(vector<int>v1, vector<int>v2){
    vector<int>ans(v1.size() + v2.size());
    int i = 0; 
    int j = 0; 
    int k = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            ans[k++] = v1[i];
            i++;
        } else{
            ans[k++] = v2[j];
            j++;
        }
    }

    while(i < v1.size()){
        ans[k++] = v1[i];
        i++;
    }
    while(j < v2.size()){
        ans[k++] = v2[j++];
        
    }
    return ans;
}

TreeNode<int>* inorderToBST(int s, int e, vector<int>&inorderVal){
    if(s > e){
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode<int>* root = new TreeNode<int>(inorderVal[mid]);
    root->left = inorderToBST(s, mid - 1, inorderVal);
    root ->right = inorderToBST(mid +  1, e, inorderVal);
    return root;

}

void convertToSortedDLL(TreeNode<int>*root, TreeNode<int>* &head){
    //base case 
    if(root == NULL){
        return;
    }
    //right part 
    convertToSortedDLL(root->right, head);
    root->right = head; 
    if(head){
        head ->left = root; 
    }
    head = root; 
    convertToSortedDLL(root->left, head);
}

TreeNode<int>* mergeTwoLinkedList(TreeNode<int>*head1, TreeNode<int>*head2){
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;
    
    while(head1 && head2){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1; 
                tail = head1; 
                head1 = head1->right;
            } else{
                tail ->right = head1; 
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else{
            if(head == NULL){
                head = head2; 
                tail = head2; 
                head2 = head2->right;
            } else{
                tail ->right = head2; 
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1){
        tail ->right = head1; 
        head1->left = tail;
        tail = head1;
        head1 = head1->right; 
    }
    if(head2){
        tail ->right = head2; 
        head2->left = tail;
        tail = head2;
        head2 = head2->right; 
    }
    return head;
}

int count(TreeNode<int> *head){
    int n = 0; 
    TreeNode<int> *temp = head; 
    while(temp){
        n++;
        temp = temp ->right;
    }
    return n;
}
TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n){
    //base case 
    if( n <= 0 || head == NULL){
        return NULL;
    }
    TreeNode<int> *left = sortedLLToBST(head, n/2);
    TreeNode<int> *root  = head; 
    root->left = left; 
    head = head->right;
    root->right = sortedLLToBST(head, n - n/2 -1);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //Approach1: using Vectors 
    // //Step1: store inorders of both BSTs
    // vector<int>in1;
    // vector<int>in2;
    // inorder(root1, in1);
    // inorder(root2, in2);
    // //Step2: Merge two arrays using native merge function
    // vector<int>inorderVal= merge(in1, in2);
    // //Step3: Use inorderToBST function to form BST
    // int i = 0;
    // TreeNode<int>* root = inorderToBST(i, inorderVal.size() - 1, inorderVal);
    // return root;

    //Approach2:Convert BST to flatten sorted LL 
    //and then merge them and convert sorted LL to BST
    
    //STEP1: Convert BST to sorted LL using SC as O(h)
    TreeNode<int>*head1= NULL;
    convertToSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode<int>*head2= NULL;
    convertToSortedDLL(root2, head2);
    head2->left = NULL;

    //STEP2:Merge Sorted Linked List 
    TreeNode<int>* head = mergeTwoLinkedList(head1, head2);

    //STEP3: Convert SortedLLtoBST
    return sortedLLToBST(head, count(head));
    


}