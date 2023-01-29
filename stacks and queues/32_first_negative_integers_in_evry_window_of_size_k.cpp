//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include<bits/stdc++.h>
using namespace std;

//optimized approach 
/*
// C++ code for First negative integer
// in every window of size k
#include <iostream>
using namespace std;

void printFirstNegativeInteger(int arr[], int k, int n)
{
	int firstNegativeIndex = 0;
	int firstNegativeElement;

	for (int i = k - 1; i < n; i++) {

		// skip out of window and positive elements
		while ((firstNegativeIndex < i)
			&& (firstNegativeIndex <= i - k
				|| arr[firstNegativeIndex] >= 0)) {
			firstNegativeIndex++;
		}

		// check if a negative element is found, otherwise
		// use 0
		if (arr[firstNegativeIndex] < 0) {
			firstNegativeElement = arr[firstNegativeIndex];
		}
		else {
			firstNegativeElement = 0;
		}
		cout << firstNegativeElement << " ";
	}
}

// Driver code
int main()
{
	int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	printFirstNegativeInteger(arr, k, n);
}

*/

vector<long long>printFirstNegativeInteger(long long int A[], long long int N, long long int K){
    deque<long long int> dq; 
    vector<long long> ans; 

    //process first window of k size 
    for(int i = 0; i < K; i++){
        if(A[i] < 0){
            dq.push_back(i);
        }
    }    

    //store answer of first k size window 
    if (dq.size() > 0){
        ans.push_back(A[dq.front()]);
    } else { 
        ans.push_back(0);
    }

    //Process for remaining windows 
    for(int i = K; i < N; i++){
        //removal 
        if(!dq.empty() && i - dq.front() >= K){
            dq.pop_front();
        }

        //addition 
        if (A[i] < 0){
            dq.push_back(i); 
        }

        //ans store 
        if (dq.size() > 0){
            ans.push_back(A[dq.front()]);
        } else { 
            ans.push_back(0); 
        }
    }

    return ans;
}

int main(){

    return 0;
}