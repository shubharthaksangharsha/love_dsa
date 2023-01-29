//https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=1

//i/p: [11, 12, 13, 14, 15, 16, 17, 18]
//o/p: [11, 15, 12, 16, 13, 17, 14, 18]

/*
Approach 1: using queue 
fetch first half elements from input queue and push to new queue 
[15, 16, 17, 18] - input queue 
[11, 12, 13, 14] - new queue 

while new queue not empty: push new queue element to input queue and pop new queue element and do same for input queue first element too 

Approach 2: using only stack
1. fetch first half of queue to stack 
2. pop element from stack back to input queue 
3. push first half of input queue to last of input queue 
4. push again first half of queue to stack 
5. now do same as approach 1 i.e while stack not empty: push stack element to input queue and pop stack element and do same for input queue first element too
*/


 #include <bits/stdc++.h> 
 using namespace std; 

void interLeaveQueue(queue < int > & q) {
    //using queue 
    // queue<int>nq; 
    // int n = q.size() /2 ;
    // for(int i = 0; i < n; i++){
    //     nq.push(q.front());
    //     q.pop();
    // }
    // while(!nq.empty()){
    //     q.push(nq.front());
    //     nq.pop();
    //     q.push(q.front());
    //     q.pop();
    // }
    
    //using stack 
    stack<int>st; 
    int n = q.size() / 2; 
    for(int i = 0; i < n ; i++){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    for(int i = 0; i < n; i++){
        q.push(q.front());
        q.pop();
    }

    for(int i = 0; i < n; i++){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    
    /*
Approach 2: using only stack
1. fetch first half of queue to stack 
2. pop element from stack back to input queue 
3. push first half of input queue to last of input queue 
4. push again first half of queue to stack 
5. now do same as approach 1 i.e while stack not empty: push stack element to input queue and pop stack element and do same for input queue first element too
*/
}