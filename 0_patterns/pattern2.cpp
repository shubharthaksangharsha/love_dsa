//Author: Shubharthak Sangharasha
/*  Date: 
        Description: 
*/

/*
n = 3
111
222
333

n = 4
1111
2222
3333
4444

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int i = 1; 
    while(i <= n){
        int j = 1; 
        while(j <= n){
            cout << i;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}