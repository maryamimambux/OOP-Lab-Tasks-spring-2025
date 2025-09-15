#include <iostream>
using namespace std;

/*

Task 2:
1. Write a simple C++ program that demonstrates direct recursion. 
Create a function printNumbers(int n) that prints numbers 
from n down to 1 by calling itself directly.

2. Next, demonstrate indirect recursion by creating two functions, 
functionA(int n) and functionB(int n). 
functionA should call functionB, and functionB should call functionA, 
forming a cycle that prints numbers in a specific pattern.
Ensure both programs have a base condition to prevent infinite loops.

*/

// 1. DIRECT RECURSION
int printNumbers(int n) {
    if(n == 0) { 
        return 0;
    }
    cout << n << " ";
    return printNumbers(n-1);
}

// 1. INDIRECT RECURSION

int functionB (int n);
int functionA(int n) {
    if(n == 0) { 
        return 0;
    } 

    cout << n << " ";
    return functionB(n-1);
}

int functionB (int n) {
    if(n == 0) { 
        return 0;
    } 

    cout << n << " ";
    return functionA(n-1);

}

int main() {

    int n = 0;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Using Direct Recursion: ";
    printNumbers(n);
    cout << endl;

    cout << "Using Indirect Recursion: ";
    functionA(n);

    return 0;
}