//Author: Shubharthak Sangharasha
/*  Date: 
        Description: 
*/


/*
n = 4

****
****
****
****

n = 3
***
***
***

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int i = 1;
    while(i++ <= n){
        int j = 1;
        while(j++ <= n){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}