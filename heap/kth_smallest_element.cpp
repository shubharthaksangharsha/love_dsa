//Author: Shubharthak Sangharasha
/*  Date: 2023-02-03 
         Description:
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

void input(vector<int>&arr){
    for(auto &i: arr){
        cin >> i;
    }
}

void display(const vector<int>arr){
    for(auto const i: arr){
        cout << i << " ";
    }
    cout << endl;
}
int main(){
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements: ";
    vector<int>arr(n);
    input(arr);
    cout << "Enter value of k: "; 
    cin >> k;
    //Approach 1: sort and return kth smallest return arr[k] TC: Nlogn and SC: O(1); 
    // sort(arr.begin(), arr.end());
    // cout << arr[k -1] << endl;
    //Approach 2: using max heap 
    //First K element(0:k-1) ke liye heap bnalo and rest element ke liye (k:n-1)
    priority_queue<int>pq; 
    //step1: push first k element
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }   
    //Step2: check rest of elements 
    for(int i = k; i < arr.size(); i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    //Step3: 0 to K elements are in heap now return the pq.top() to get the Kth element
    cout << "Ans: " << pq.top() << endl;
    
    return 0;
}