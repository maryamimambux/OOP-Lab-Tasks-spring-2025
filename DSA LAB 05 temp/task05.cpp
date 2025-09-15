#include <iostream>
using namespace std;

/*

Task 5:

    Implement a Sudoku solver using the backtracking technique. The program should take a
    partially filled 9x9 Sudoku grid and fill the empty cells (represented by 0) to solve the puzzle.
    Your algorithm should:
    1. Find an empty cell.
    2. Try placing a number from 1 to 9 in the empty cell.
    3. Check if the number is valid in the current row, column, and 3x3 subgrid.
    4. If valid, recursively call the function to solve the rest of the puzzle.
    5. If the recursive call doesn't lead to a solution,
    backtrack by resetting the cell to 0 and trying the next number.

*/

const int SIZE = 9;

void printsudokuGrid(int grid[SIZE][SIZE]) {
    cout << "Sudoku Grid: \n";

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << grid[i][j] << "  ";

            if(j==2 || j==5) cout << " ";
        }
        cout << endl;
        if(i==2 || i==5) cout << "\n";
    }
    cout << endl;
}

bool isSolved(int grid[SIZE][SIZE]) {
    cout << "Sudoku Grid: \n";

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) { 
            if( grid[i][j] == 0) return false;
        } 
    }
    
    return true;
}

bool isfree(int index) {

}

int main() {

    int grid[9][9] = {
                    {1,0,3, 0,5,0, 0,8,9},
                    {0,2,3, 0,5,6, 7,0,9},
                    {1,2,0, 4,5,0, 0,8,9},

                    {0,2,3, 4,5,0, 7,8,9},
                    {1,0,3, 4,0,6, 0,0,9},
                    {0,2,0, 4,5,6, 7,0,9},

                    {1,0,3, 4,0,6, 0,8,9},
                    {1,0,3, 4,0,6, 7,0,9},
                    {1,2,0, 0,5,6, 7,8,9}
    };
 
    printsudokuGrid(grid);

    int n = 0;
    int row = 0, col = 0;

    while (!isSolved(grid)) {
        cout << "Enter position - row and column: ";
        cin >> index;

        if( isfree(index) ) {
            cout << "Enter an integer: ";
            cin >> n;
            if( isValid(n) ) {
                cout << n << " is successfully entered at " << 
            }
        }
        else {
            cout << "Position " << index << " is not free.\nPlease try again!\n"; 
        }
    }



    return 0;
}