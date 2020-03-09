#include <iostream>
using namespace std;

struct node {
    int val;
    node* next = nullptr;
};

class Queue {
public:
    node* head = nullptr;
    node* tail = nullptr;
    int remove();
};

int Queue::remove() {
    //check for empty
   if (head == tail){
       head = nullptr;
       tail = nullptr;
       cout << "queue's empty ";
    }

   else {
    //remove the node   
    node* temp = new node;
    int val = head->val;
    temp = head;
    head = head->next;
    delete temp;  
    temp = nullptr;
    return val;
   }
}

// MAIN FUNCTION
int main() {
    int result;
    Queue q;
    
    result = q.remove();

    return 0;
}
