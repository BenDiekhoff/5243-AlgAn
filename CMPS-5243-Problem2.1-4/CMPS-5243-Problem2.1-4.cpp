//2.1-4
//Consider the problem of adding two n - bit binary integers, stored in two n -
//element arrays A and B.The sum of the two integers should be stored in binary
//form in an(n + 1) element array C.State the problem formally and write 
//pseudocode for adding the two integers.
//

#include <iostream>
using namespace std;

int main() {
	int a[] = { 1,0,1,1,0,1 };
	int b[] = { 1,0,1,1,1,0 };
	int c[7];

	int n = sizeof(a) / sizeof(a[0]);

	int carryOne = 0;
	int sum = 0;

	for (int i = n; i > -1; i--) {
		if (i == 0) {
			c[i] = carryOne;
			carryOne = 0;
		}
		

		else {
			sum = a[i - 1] + b[i - 1] + carryOne;
			if (sum > 2) {
				c[i] = 1;
				carryOne = 1;
			}
			else if (sum > 1) {
				c[i] = 0;
				carryOne = 1;
			}
			else {
				c[i] = sum;
				carryOne = 0;
			}
		}
		cout << carryOne << endl;

	}
	cout << endl;
	for (int i = 0; i <= 6; i++)
		cout << c[i] << " ";

	cout << endl;
	return 0;

}