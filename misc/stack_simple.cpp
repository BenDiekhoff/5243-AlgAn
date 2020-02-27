#include <iostream>
using namespace std;

class Stack{
public: // made everything public to make the code simpler
    int top = -1; // stack is empty at -1, 
    int A[6];
    int n = sizeof(A)/sizeof(A[0]);
    bool full();
    void push(int val);
};

bool Stack::full(){
    if (top == n -1)
        return true;
    else return false;
}

void Stack::push (int val){
    if (!full())
        A[++top] = val; //increment top, then add the value to A
    else
        cout << "stack's full\n";
}

// MAIN
int main(){
    Stack S;
    S.push(100);    // function call to push 100
    for (auto i : S.A)
        cout << i << "\n";
    return 0;
}
