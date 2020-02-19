#pragma once
#include <iostream>
using namespace std;


class Stack{
public: //private:
    int top = -1;
    int A[6] = {-1,-1,-1,-1,-1,-1};
//public:
    bool empty();
    bool full();
    void push(int val);
    int pop();
    int peek();
};

bool Stack::empty(){
    if (top == -1)
        return true;

    else return false;
}

bool Stack::full(){
    int n = sizeof(A)/sizeof(A[0]);
    
    if (top == n -1)
        return true;

    else return false;
}

void Stack::push (int val){
    if (!full())
        A[++top] = val;
}

int Stack::pop(){
    if (!empty())
        return A[top--];
}


int Stack::peek(){
    if (!empty()){
        //cout << "The top is " << top << " and holds the value " << A[top] << '\n';
        return A[top];
    }
}