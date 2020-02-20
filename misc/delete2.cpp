#include <iostream>
using namespace std;
int main()
{
    //int a = 5;
    //cout << "Value of a: " << a << "\n";
    //cout << "Address of a: " << &a << "\n";    
    int *intptr = new int;
    *intptr = 5;
    //cout << "Address pointed to by intptr: " << intptr << "\n";    
    //intptr = &a;
    cout << "Value intptr points to: " << *intptr << "\n";
    cout << "Address intptr points to: " << intptr << "\n";    
    delete intptr;    
    //cout << "Value of a after deleting intptr: " << a << "\n";
    cout << "Value of *intptr after deleting intptr: " << *intptr << "\n";
    cout << "Address intptr points to: " << intptr << "\n";   
    intptr = nullptr;    
    return 0;
}