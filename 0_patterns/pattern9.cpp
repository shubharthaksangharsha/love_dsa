//Author: Shubharthak Sangharasha
/*  Date: 
         Description:
*/
/*
n = 4
1
2 3
3 4 5
4 5 6 7
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 1; 
    while(i <= n){
        int row = i;
        int j = 1;
        while(j <= i){
            cout << row++ << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}