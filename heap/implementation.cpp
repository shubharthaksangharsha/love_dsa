//Author: Shubharthak Sangharasha
/*  Date: 2023-02-03 19:48:43
         Description: Immplementation of Heap 
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data; 
        Node* left;
        Node* right;
        //Default Constructor
        Node(){
            this -> data = 0;
            this -> left = NULL;
            this -> right= NULL;
        }
        //Parammetized constructor 
        Node(int data){
            this -> data = data; 
            this -> left = NULL;
            this -> right = NULL;
        }

        Node(int data, Node* left, Node* right){
            this -> data = data; 
            this -> left = left; 
            this -> right = right;
        }
};

class heap{
    public: 
        int arr[100];
        int size;
        heap(){
            arr[0] = -1; 
            size = 0; 
        }
        void insert(int val){
            size++;
            int index = size; 
            arr[index] = val; 
            while(index > 1){
                int parent = index / 2; 
                if (arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent; 
                } else{
                    return;
                }

            }
        }
        void deletefromheap(){
            if(size == 0){
                cout << "Heap is Empty!" << endl;
                return;
            }
            //replace root node to last node
            arr[1] = arr[size];
            //delete last node
            size--;
            //take root node to its correct position 
            int i = 1; 
            while(i < size){
                int leftIndex = 2 * i;
                int rightIndex = 2 * i + 1; 
                if(leftIndex < size && arr[i] < arr[leftIndex]){
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                } else if(rightIndex < size && arr[i] < arr[rightIndex]){
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                } else{
                    return;
                }
            }

        }
        void print(){
            for(int i = 1; i <= size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        } 
};

void heapify(int arr[], int n, int i){
    int largest = i; 
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left <= n && arr[largest] < arr[left]){
        largest = left; 
    }
    if (right <= n && arr[largest] < arr[right]){
        largest = right; 
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n){
    for(int i = n / 2; i >0; i--){
        heapify(arr, n, i);
    }
}
void print(int arr[], int n){
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(int arr[], int n){
    buildHeap(arr, n);
    int size = n ; 
    while(size > 1){
        //step1: swap 
        swap(arr[1], arr[size]);
        //step2: size -- 
        size--; 
        //step3: heapify 
        heapify(arr, size, 1); 
        
    }
}


// int main(){
//     // heap h; 
//     // h.insert(50);
//     // h.insert(55);
//     // h.insert(53);
//     // h.insert(52);
//     // h.insert(54);
//     // h.print();
//     // h.deletefromheap();
//     // h.print();
//     // int arr[6] = {-1, 54, 53, 55, 52, 50};
//     // int n = 5;
//     // cout << "Before Sort: ";
//     // print(arr, n);
//     // heapSort(arr, n);
//     // cout << "After sort: ";
//     // print(arr, n);

//     cout << "Using Priority Queue" << endl;
//     priority_queue<int>pq; 
//     pq.push(1); 
//     pq.push(2); 
//     pq.push(3); 
//     pq.push(4); 
//     pq.push(5);
//     cout << pq.top() << endl; 
//     pq.pop();
//     cout << pq.top() << endl;

//     //min heap 
//     priority_queue<int, vector<int>, greater<int> >minHeap;
//     minHeap.push(1);
//     minHeap.push(2);
//     minHeap.push(3);
//     minHeap.push(4);
//     cout << minHeap.top() << endl;
    
//     return 0;


// }