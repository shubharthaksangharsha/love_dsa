//https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1

//Author: Shubharthak Sangharasha
/*  Date: 2023-01-18 00:38:59
         Description:
*/
#include<bits/stdc++.h>
using namespace std;

//return the address of the string
char* reverse(char *S, int len)
{
    stack<char>s; 
    for(int i = 0; i < len; i++){
        s.push(S[i]);
    }
    int i = 0;
    while(s.size()){
        S[i] = s.top();
        s.pop();
        i++;
    }
    return S;
}

// int main(){
//     string str;
//     cout << "Enter your string: " ;
//     cin >> str; 
//     stack<char>s; 
//     for(int i = 0; i < str.size(); i++){
//         s.push(str[i]);
//     }
//     string ans; 
//     while(s. ){
//         ans.push_back(s.top());
//         s.pop();
        
//     }
//     cout << "Reverse string: " << ans << endl; 
//     return 0;
// }