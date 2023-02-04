//https://www.codingninjas.com/codestudio/problems/median-in-a-stream_975268?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=1


#include<bits/stdc++.h>
using namespace std;

int signum(int a, int b){
	if (a == b){
		return 0;
	} 
	if (a > b){
		return 1;
	}
	return -1;
}
void callMedian(int element, vector<int>&arr, priority_queue<int>&maxi,
priority_queue<int, vector<int>, greater<int>>&mini, int &median){
	switch (signum(maxi.size(), mini.size())){
		case 0: //same 
			if(element > median){
				mini.push(element);
				median = mini.top(); 
			} else { 
				maxi.push(element);
				median = maxi.top();
			}
			break;
		case 1: 
			if(element > median){
				mini.push(element);
				median = (mini.top() + maxi.top())/2;
			} else { 
				mini.push(maxi.top());
				maxi.pop();
				maxi.push(element);
				median = (mini.top() + maxi.top())/2;

			}
			break;
		case -1:
			if(element > median){
				maxi.push(mini.top());
				mini.pop();
				mini.push(element);
				median = (mini.top() + maxi.top())/2;
			} else {
				maxi.push(element);
				median = (mini.top() + maxi.top())/2;
			}
			break;
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	//Approach 1: using insertion sort 
	//Approach 2: using min and max heap 
	vector<int>ans; 
	priority_queue<int>maxHeap; 
	priority_queue<int, vector<int>, greater<int> >minHeap;
	int median = 0; 
	for(int i = 0; i < n; i ++){
		callMedian(arr[i],arr, maxHeap, minHeap, median);
		ans.push_back(median);
	}
	return ans;
}
