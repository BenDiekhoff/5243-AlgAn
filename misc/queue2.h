#pragma once   
#include <iostream>
using namespace std;

class Queue{
    public:
    int a[6] = {-1,-1,-1,-1,-1,-1};
    int head = 0;
    int tail = 0; 
    int len = sizeof(a)/sizeof(a[0]);


    void enq(int val){
        // if (head == tail + 1 || (head == 0 && tail == len) )
        //     {
        //         cout << "Q's full";
        //         return;
        //     }

        
        a[tail] = val;
        tail = (tail + 1) % len;
        // if (tail == len){
        //     tail = (tail + 1) % len;
        //     cout << "this";
        // }
        // else
        // {
        //     tail = tail + 1;
        //     cout << "that";
        // }
        
    }

    int dq(){
        // if (tail == head)
        //     cout << "Q's empty\n";
        // else {
        head++;
        return a[head -1];

        //}
    }

    void display(){
        for (int i = 0; i < len; i++ )
        cout << head << '\t' << tail << '\t' << a[(i+ head) % 6] <<"\n";
    }
};