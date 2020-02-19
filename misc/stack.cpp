#include <iostream>
#include "stack_simple.h"
using namespace std;

const int NUM = 7;

int main(){
    int a[NUM];
    int test = 1;
    Stack s;



    for (auto x : s.A){  //push 1 - 6
        s.push(test++);
        s.peek();

    }
    
    s.push(7);
    
    for (auto x : s.A)  //print stack
        cout << x << "\n";

    s.peek();

    for (auto x : a){    //pop stack 7 times
    int y = s.pop();
    cout << '=' << y << " \n";
    }

s.peek();

    s.push(7);
s.peek();


    for (auto x : s.A)  //print stack
        cout << x << "\n";

    





    
    


    return 0;
}

