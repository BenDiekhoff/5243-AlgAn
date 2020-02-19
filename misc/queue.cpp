#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue q;
    for (int i =1; i < 101; i++)
        q.enq(i);

    q.display();
    cout << "------------------------------\n";
    //system("pause");    
    for (int i = 1; i < 100; i++)
        q.deq();

    q.display();
    cout << "------------------------------\n";
    //system("pause");

    for (int i = 72; i < 123; i++)
        q.enq(i);

    q.display();
    //system("pause");
    return 0;
}