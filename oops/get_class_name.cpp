//Author: Shubharthak Sangharasha
/*  Date: 
         Description:
*/
#include<bits/stdc++.h>
#include "Hero.cpp"
using namespace std;
string get_name(Hero n){
    string ans;
    string temp = typeid(n).name();
    for(int i = 0; i < temp.size(); i++){
        if (i== 0){
            continue;
        } 
        ans.push_back(temp[i]);
    }
    return ans;
}

int main(){
    Hero suresh(70, 'C');
    Hero ritesh(suresh);
    suresh.print();
    ritesh.print();
    cout << get_name(suresh) << endl;
    return 0;
}