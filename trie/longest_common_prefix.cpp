//https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?leftPanelTab=0
#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

class TrieNode{
    public:
        char data; 
        TrieNode* children[26];
        bool isTerminal;
        int childCount;
        TrieNode(char d){
            this -> data = d; 
            for(int i = 0 ; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
            childCount = 0;
        }
};
class Trie{
    TrieNode* root;
    void insertUtil(TrieNode* root, string word){
        //base case (if reached end)
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        //get index 
        int index = word[0] - 'a';
        TrieNode* child; 
        //if present
        if(root->children[index] != NULL){
            child = root->children[index];
        } else{
            //not present 
            child = new TrieNode(word[0]); 
            root->childCount++;
            root->children[index] = child;
        }
        //Recursion
        insertUtil(child, word.substr(1));
    }

    public:
        Trie(char ch){
            root = new TrieNode(ch);
        }
        void insert(string word){
            insertUtil(root, word);
        }
        void lcp(string str, string &ans){
            for(int i = 0; i < str.size(); i++){
                char ch = str[i];
                if(root->childCount == 1){
                    ans.push_back(ch);
                    //aage badh jao 
                    int index = ch - 'a';
                    root = root->children[index];
                } else {
                    break;
                }
                if(root->isTerminal){
                    break;
                }
            }
        }
};
string longestCommonPrefix(vector<string> &arr, int n)
{

    string ans=""; 
    Trie *t = new Trie('\0');
    //insert kardo all strings into trie 
    for(int i = 0; i < n; i++){
        t->insert(arr[i]);
    }
    string first = arr[0];
    t->lcp(first, ans);
    return ans;
    // //for traversing all character of first string
    // for(int i = 0; i < arr[0].length(); i++){
    //     char ch = arr[0][i];
    //     bool match = true;
    //     //for remaining strings 
    //     for(int j = 1; j < n; j++){
    //         //not match 
    //         if(arr[j].size() < i || ch != arr[j][i]){
    //             match = false;
    //             break;
    //         }
    //     }
    //     if(match == false){
    //         break;
    //     } 
    //     ans.push_back(ch);
    // }
    // return ans;
}


