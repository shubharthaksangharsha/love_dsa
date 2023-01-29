//Author: Shubharthak Sangharasha
/*  Date: 
         Description:
*/
#include<bits/stdc++.h>
#include "Hero.cpp"
using namespace std;
int main(){
    Hero a(2, 'A');
    cout << a.getHealth() << endl;
    cout << a.level << endl;
    // //Statically 
    // Hero a; 

    //Dynamically 
    Hero *b = new Hero(1, 'B');
    // b -> setHealth(60);
    // b -> level = 'A';
    cout << b -> getHealth() << " " << b -> level  << endl;
    // //another way 
    cout << "(Another way)Health: " <<  (*b).getHealth() << " " << "Level: " << (*b).getLevel() << endl;
    return 0;
}