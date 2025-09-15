#include <iostream>
using namespace std;

/*

Task 3:

1. Implement a C++ function sumTail(int n, int total) that 
calculates the sum of numbers from 1 to n using tail recursion. 
The recursive call should be the last operation in the function.

2. Implement another function sumNonTail(int n) that 
calculates the same sum using non-tail recursion. 
This function should perform an operation (e.g., addition) 
after the recursive call returns. 

Compare the two implementations and explain the difference in their call stacks.

*/

// 1. TAIL RECURSION
int sumTail(int n, int total) {
    if(n == 0) {
        return total;
    } 
    return sumTail(n-1, total+n);
}


// 2. NON-TAIL RECURSION
int sumNonTail(int n) {
    if(n == 1) {
        return 1;
    }

    return n + sumNonTail(n-1);
}

int main() {

    int n = 0, total = 0;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Using TAIL Recursion: ";
    cout << sumTail(n, total) << endl;

    cout << "Using NON-TAIL Recursion: ";
    cout << sumNonTail(n) << endl;

    return 0;
}