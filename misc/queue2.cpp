#include <iostream>
#include "queue2.h"
using namespace std;
int main()
{
    Queue q;
    q.dq();
    cout << q.tail << "\t" << q.head << "\n";
    for (int i = 0; i < 6; i++){
        q.enq(i);
        cout << q.tail << "\t" << q.head << "\n";
    }
    q.display();
    q.dq();
    q.dq();
    q.display();
    return 0;
}