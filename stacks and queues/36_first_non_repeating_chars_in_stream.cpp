//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A){
    unordered_map<char, int>count;
    queue<int>q;
    string ans; 

    for(int i = 0; i < A.size(); i++){
        char ch = A[i];
        //increase count 
        count[ch]++;

        //queue mein push kardo 
        q.push(ch);

        while(!q.empty()){
            if(count[q.front()] > 1){
                //repeating character 
                q.pop();
            } else { 
                //non repeating character 
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }   
    } 
    return ans;
}

int main(){
    string A;
    cout << "Enter the string: ";
    cin >> A;
    cout << FirstNonRepeating(A) << endl;
}