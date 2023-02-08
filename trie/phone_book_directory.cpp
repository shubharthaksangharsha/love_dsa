//https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

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

    
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }
    void addSuggestions(TrieNode* curr, vector<string>& temp, string prefix){
    if(curr->isTerminal){
        temp.push_back(prefix);
    }
    for(char ch = 'a'; ch <= 'z'; ch++){
        TrieNode *next = curr->children[ch-'a'];
        if(next != NULL){
            prefix.push_back(ch);
            addSuggestions(next, temp, prefix);
            prefix.pop_back();
        }
    }
}
vector<vector<string> > getSuggestions(string str){
    TrieNode* prev = root; 
    vector<vector<string> >output; 
    string prefix = "";
    for(int i = 0; i < str.length(); i++){
        char last = str[i];
        prefix.push_back(last);
        
        //check for last char 
        TrieNode* curr  = prev->children[last - 'a'];

        //if not found 
        if (curr == NULL){
            break;
        }
        //if found 
        vector<string>temp;
        addSuggestions(curr, temp, prefix);
        output.push_back(temp);
        temp.clear();
        prev = curr; 
    }
    return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //Creation of trie 
    Trie *t = new Trie();
    //insert all contact in trie 
    for(int i = 0; i < contactList.size(); i++){
        string str = contactList[i];
        t-> insert(str);
    }
    //return ans
    return t->getSuggestions(queryStr);
}