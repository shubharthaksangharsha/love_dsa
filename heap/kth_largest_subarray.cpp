//https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0

#include<bits/stdc++.h>
#include "implementation.cpp"
using namespace std;

#include<algorithm>
#include<queue>
int getKthLargest(vector<int> &arr, int k)

{
	//APPROACH 1: Naive APPROACH using BRute force 
	/*find all sum and then sort them and return 
	arr[n -k]* TC: N^2, SC: O(N)/
	int n = arr.size();
	vector<int>sumStore;
	for(int i = 0; i < n; i++){
		int sum = 0; 

		for(int j = i; j < n; j++){
			sum += arr[j];
			sumStore.push_back(sum);
		}
	}
	//sort all sum 
	sort(sumStore.begin(), sumStore.end());
	return sumStore[sumStore.size() - k];*/

	//Approach 2: using Min Heap 
	priority_queue<int, vector<int>, greater<int> >pq; 
	int n = arr.size();
	for(int i = 0; i < n; i++){

		int sum = 0; 
		for(int j = i; j < n; j++){
			sum += arr[j];

			if(pq.size() < k){
				pq.push(sum);
			} else {
				if(sum > pq.top()){
					pq.pop();
					pq.push(sum);
				}
			}
		}
	}
		return pq.top();
}