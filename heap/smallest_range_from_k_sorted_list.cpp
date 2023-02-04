//https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0
 
#include<limits.h>
#include<queue>
using namespace std; 

class node{
    public:
        int data; 
        int row; 
        int col; 

        node(int d, int row, int col)  {
            this -> data = d; 
            this -> row = row;
            this -> col = col;
        }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a -> data > b -> data;
        }
};
int kSorted(vector<vector<int>> &a, int k, int n) {

    //STEP1: Create  a min heap for starting k elements 
    //and also keeping track of min and max 
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> pq; 

    for(int i = 0; i < k; i++){
        int element = a[i][0];
        mini = min(mini, element); //track of curr min
        maxi = max(maxi, element); //track of curr max
        pq.push(new node(element, i, 0));
    }

    int start = mini, end = maxi; 
    //process ranges 
    while(!pq.empty()){
        //mini fetched 
        node* temp = pq.top();
        pq.pop();
        mini = temp->data; 

        //updating ranges or answer 
        if(maxi  - mini < end - start){
            start = mini; 
            end = maxi; 

        }
        //checking next element available or not 
        if(temp -> col + 1< n){
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            pq.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        } else {
            break;
        }
    }
    //returning difference + 1 (as mentioned in question)
    //i.e (7 - 7) should give 1 (i.e 7 - 7 = 0 + 1 = 1)
    return (end - start + 1);
}