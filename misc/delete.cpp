// #include <iostream>
// using namespace std;

// int main() {

// int a = 5;

// int* intptr = new int;
// //intptr = &a;
// delete intptr;  //comment out to make the code work
// intptr = nullptr;



// //vvvvvvvvvvvvvvvvvvvvv WORKS vvvvvvvvvvvvvvvvvvvvvv
// // int* a = new int;
// // *a = 4;

// // int* intptr = a;
// // cout << intptr << " ";
// // intptr = a;
// // delete intptr; 
// // intptr = nullptr;

// return 0;
// }


#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    cout << "Value of a: " << a << "\n";
    cout << "Address of a: " << &a << "\n";    
    int *intptr = new int;
    cout << "Address pointed to by intptr: " << intptr << "\n";    
    intptr = &a;
    cout << "Value intptr points to: " << *intptr << "\n";
    cout << "Address intptr points to: " << intptr << "\n";    
    delete intptr;    
    cout << "Value of a after deleting intptr: " << a << "\n";
    intptr = nullptr;    
    return 0;
}