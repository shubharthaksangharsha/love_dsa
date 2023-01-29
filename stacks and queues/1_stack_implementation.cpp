//https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209

#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int* arr;
    int stop; 
    int size;
    
public:
    
    Stack(int capacity) {
        size = capacity;
        arr = new int[capacity];
        stop = -1;
    }

    void push(int num) {
        if(size - stop > 1){
            arr[++stop] = num;
            return;
        }

    }

    int pop() {
        if (stop >= 0){
            return arr[stop--];
        }
        return -1;
    }
    
    int top() {
        if (stop >= 0){
            return arr[stop];
        }
        return -1;
       
    }
    
    int isEmpty() {
        if (stop == -1){
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if (stop == size -1){
            return 1;
        }
        return 0;
    }
    
};
// //Author: Shubharthak Sangharasha
// /*  Date: 2023-01-17 23:56:10
//          Description: Implementation of stack using Array
// */
// #include<bits/stdc++.h>
// using namespace std;

// class mystack{
    
//     int top;
//     int* arr;
//     public:
//         int size;
//         //Default constructor
//         mystack(){
//             top = -1;
//             size = 5;
//             arr = new int[size];
//         }
//         //Parametized constructor
//         mystack(int size){
//             this -> size = size;
//             arr = new int[size];
//             top = -1;
//         }
        
//         void push(int element);
//         void pop();
//         int peek();
//         bool empty();
        
// };

// void mystack::push(int element){
//     if (size - top > 1){
//         top++;
//         arr[top] = element;
//         return;
//     }
//     cout << "Stack Overflow!" << endl;
// }

// void mystack::pop(){
//     if (top >= 0){
//         top--;
//         return;
//     }
//     cout << "Stack Underflow!" << endl;
// }

// int mystack::peek(){
//     if (top >= 0){
//         return arr[top];
//     }
//     cout << "Stack is empty" << endl;
//     return -1; 
// }

// bool mystack::empty(){
//     if (top == -1){
//         return true;
//     }
//     return false;
// }

// int main(){
//     mystack s; 
//     s.push(22);
//     s.push(43);
//     s.push(44);
//     s.push(44);
//     s.push(44);
//     cout << s.size << endl;
//     s.push(44);

//     cout << s.peek() << endl;
//     s.pop();
//     cout << s.peek() << endl;
    
//     s.pop();
//     cout << s.peek() << endl;

//     s.pop();
//     // cout << s.peek() << endl;

//     if(s.empty()){
//         cout << "stack is empty" << endl;
//     } else {
//         cout << "stack is not empty" << endl;
//     }

//     //creation of stack 
//     // stack<int>s; 

//     // //push 
//     // s.push(2);
//     // s.push(19);

//     // //pop
//     // s.pop();


//     // cout << "Printing top element: " << s.top() << endl;

//     // if (s.empty()){
//     //     cout << "Stack is empty" << endl;
//     // } else {
//     //     cout << "Stack is not empty" << endl;
//     // }
//     return 0;
// }