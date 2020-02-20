#pragma once   
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

    void enq(int val);
    void deq();
    void display();
};

void Queue::enq(int val) {
    node* temp = new node;
    temp->val = val;

    if (head == nullptr) {
        head = temp;
        tail = temp;
    }

    else {
        tail->next = temp;
        tail = temp;
    }
}

void Queue::deq() {
   if (head == tail){
       head = nullptr;
       tail = nullptr;
       cout << "queue's empty ";
       return;
    }

   else {
    node* temp = new node;
    temp = head;
    head = head->next;
    delete temp;  
    temp = NULL;  
   }
}

 void Queue::display() {
    node* temp = new node;
    temp = head;
    while (temp != nullptr) {
        cout << temp->val << "\n";
        temp = temp->next;
    }
}



// vvvvvvvvvvvvvvvvvvvvvvvv  BAD!  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//  void Queue::deq() {
//      node* temp = head->next;
//      head = temp;
//    //  delete temp;
//    //  temp = nullptr;
//  }

//  void Queue::display(){
//      node* temp = head;
//      while(temp != nullptr){
//          cout << temp->val << "\n";
//          temp = temp->next;
//      }

//  }



