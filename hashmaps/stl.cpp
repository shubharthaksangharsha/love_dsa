//Author: Shubharthak Sangharasha
/*  Date: 2023-02-04 12:46:41
         Description: Use of Hashmap in C++
*/
#include<bits/stdc++.h>
//#include<unordered_map>  library to import unorderedmap
using namespace std;

int main(){
    //map<string, int> mp2; this will use binary search tree behind the scene (TC: log N)
    unordered_map<string, int> mp; //This will use hashing i.e hash tables behind the scene(TC: O(1))
    //Insertion
    //1 
    pair<string, int>p = make_pair("shubharthak", 2);
    mp.insert(p);

    //2 
    pair<string, int> p2("is", 3);
    mp.insert(p2);

    //3 
    mp["best"] = 10; 
    mp["best"] = 5; //replace the old value with new value 
    //Search
    cout << mp["shubharthak"] << endl; //print the value corresponding to the provided key 

    cout << mp.at("is") << endl;

    //Important concept 
    //cout << m.at("unknownKey") << endl; // this will give an error if no key has been found 

    // cout << mp["unknownKey"] << endl; //however this will just create an 0 value for the given key 
    //cout << m.at("unknownKey") << endl; if again this line come after mp["unknownKey"] then it will give 0 and no error.

    //size 
    cout << mp.size() << endl;

    //to check presence 
    cout << mp.count("bro") << endl; //if key present give 1 else give 0 
    cout << mp.count("shubharthak") << endl; 

    //erase 
    cout << "size before erase: " << mp.size() << endl;
    mp.erase("shubharthak"); 
    cout << "size after erase: " << mp.size() << endl; 

    //print map using pairs
    cout << "Printing Map using Pair:-" << endl;
    for(auto i: mp){ //mp data presence in form of pair and pair values can be accessed using .first and .second method 
        cout << i.first << ": " << i.second << endl;
    }

    //iterator
    cout << "Printing Map using Using Iterator" << endl;
    unordered_map<string, int> :: iterator it = mp.begin();
    while(it != mp.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
    return 0;
}