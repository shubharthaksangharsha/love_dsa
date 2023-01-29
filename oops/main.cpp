//Author: Shubharthak Sangharasha
/*  Date: 
         Description:Setters and Getters and access modifiers
*/
#include<bits/stdc++.h>
using namespace std;
class Hero{
    int health;
    public:
    char level;
    void print(){
        cout << level << endl;
    }
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }
    void setHealth(int h){
        health = h;
    }
    void setLevel(char ch){
        level = ch;
    }
};

int main(){
    Hero shubh;
    cout << sizeof(shubh) << endl;
    shubh.setHealth(50);
    cout << shubh.getHealth() << endl;
    return 0;
}