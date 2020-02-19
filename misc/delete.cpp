#include <iostream>
using namespace std;

int main() {

int a = 5;

int* intptr = new int;
//intptr = &a;
delete intptr;  //comment out to make the code work
intptr = nullptr;



//vvvvvvvvvvvvvvvvvvvvv WORKS vvvvvvvvvvvvvvvvvvvvvv
// int* a = new int;
// *a = 4;

// int* intptr = a;
// cout << intptr << " ";
// intptr = a;
// delete intptr; 
// intptr = nullptr;

return 0;
}
