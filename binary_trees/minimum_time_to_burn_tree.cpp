//https://practice.geeksforgeeks.org/problems/burning-tree/1

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

class Solution {
  private:
    //do step 1 and step 2
    Node* createParentMapping(Node* root, int target,
    map<Node*, Node*>&nodeToParent){
        Node* res = NULL; 
        queue<Node*>q;
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                res = front;
            }
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    int burnTree(Node* root, map<Node*, Node*>&nodeToParent){
        map<Node*, bool>visited; 
        queue<Node*>q; 
        q.push(root);
        visited[root] = true;
        int ans = 0;
        while(!q.empty()){
            bool flag = false;
            int size = q.size();
            for(int i = 0; i < size; i++){
                //process neighbouring nodes 
                Node* front = q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right]){
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
  public:
    int minTime(Node* root, int target) 
    {
        //Algo:
        //Step1: Create nodeToParent mapping 
        //Step2: find target node 
        //Step3: burn the tree in min time 
        int ans = 0; 
        map<Node*, Node*>nodeToParent; 
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        return burnTree(targetNode, nodeToParent);
    }
};