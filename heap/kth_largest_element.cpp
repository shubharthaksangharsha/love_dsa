//https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_1115488?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

int largest_element(vector<int>arr, int n, int k){
	priority_queue<int, vector<int>, greater<int> >pq;
	for(int i = 0; i< k; i++){
		pq.push(arr[i]);
	}

	for(int i = k ; i < n; i++){
		if(pq.top() < arr[i]){
			pq.pop(); 
			pq.push(arr[i]);
		}
	}
	return pq.top();
}
int smallest_element(vector<int>arr, int n, int k){
	priority_queue<int>pq;
	for(int i = 0; i< k; i++){
		pq.push(arr[i]);
	}

	for(int i = k ; i < n; i++){
		if(pq.top() > arr[i]){
			pq.pop(); 
			pq.push(arr[i]);
		}
	}
	return pq.top();
}
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	vector<int>ans;
	//for smallest element use max heap 
	ans.push_back(smallest_element(arr, n, k));
	//for largest element use min heap 
	ans.push_back(largest_element(arr, n, k));
	return ans;

}