//Author: Shubharthak Sangharasha
/*  Date: 2023-02-05 18:20:40
         Description: Implementation of Tries Data Structure.
*/
#include<bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode{
    public:
        char data; 
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char d){
            this->data = d; 
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};
class Trie {
private:
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
            root->children[index] = child;
        }
        //Recursion
        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word){
        //base case 
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        } else{
            return false;
        }
        return searchUtil(child, word.substr(1));

    }

    bool prefixUtil(TrieNode* root, string word){
        //base case 
        if(word.length() == 0){
            return true;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        } else{
            return false;
        }
        return prefixUtil(child, word.substr(1));
    }
    void removeUtil(TrieNode* root, string word){
        //base case 
        if(root == NULL){
            return;
        }
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child; 
        if (root->children[index] != NULL){
            child = root->children[index];
        } else{
            child = NULL;
        }
        removeUtil(child, word.substr(1));
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root, word);
    }   

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
    //Delete Word in the Trie
    void removeWord(string word){
        removeUtil(root, word);
    }
};

int main(){
    Trie* t = new Trie();
    t -> insert("abcd");
    t -> removeWord("abcd");
    cout << t -> search("abcd") << endl;
}
