//https://www.codingninjas.com/codestudio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker


/*
approach 1:  using dequue 
i/p: [2, -5, -1, 7, -3, -1, -2], k = 2
o/p: []

2 dequeue i.e maxi and mini 
maxi = decreasing order maximum element in k size window
mini = increasing order minimum element in k size window

* process first k elements
* removal: i - k  >= k
* addition: 
*/
#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k){
    deque<int>maxi(k);
    deque<int>mini(k);
    
    //Addition of first k size window 
    for(int i = 0; i < k ; i++){
        //addition logic 

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0; 

    //process next k windows 
    for(int i = k; i < n; i++){
        ans += arr[maxi.front()] + arr[mini.front()];
        //next window 
        //removal 
        while(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }
        
        while(i - mini.front() >= k){
            mini.pop_front();
        }
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
 
    //make sure to consider last window 
    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;

}
int main(){
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;
    return 0;
}