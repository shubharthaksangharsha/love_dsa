//https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
#include<bits/stdc++.h>
using namespace std;

class petrolPump{
    
};

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int balance = 0; 
        int start = 0; 
        int deficit = 0; 
        for(int i = 0; i < n; i++){
            if (balance < 0){
                deficit += balance; 
                start = i + 1; 
                balance = 0;
            }
        }

        if(deficit + balance >= 0){
            return start;
        }
        return -1;
    }
};

