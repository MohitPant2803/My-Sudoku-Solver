#include <iostream>
#include <vector>
#include<limits>
#include <unordered_set>
#include <sstream>
using namespace std;

const int SIZE = 9;

bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (board[startRow + r][startCol + c] == num)
                return false;

    return true;
}

bool isValidSudokuBoard(vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        unordered_set<int> rowSet, colSet, boxSet;
        for (int j = 0; j < SIZE; ++j) {
            int rowVal = board[i][j];
            int colVal = board[j][i];
            int boxVal = board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3];

            if (rowVal != 0) {
                if (rowSet.count(rowVal)) return false;
                rowSet.insert(rowVal);
            }

            if (colVal != 0) {
                if (colSet.count(colVal)) return false;
                colSet.insert(colVal);
            }

            if (boxVal != 0) {
                if (boxSet.count(boxVal)) return false;
                boxSet.insert(boxVal);
            }
        }
    }
    return true;
}


bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printFancyBoard(const vector<vector<int>>& board) {
    cout << "+-------+-------+-------+" << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == 0)
                cout << ". ";
            else
                cout << board[row][col] << " ";

            // Vertical separator after every 3 columns
            if ((col + 1) % 3 == 0)
                cout << "| ";
        }
        cout << endl;

        // Horizontal separator after every 3 rows
        if ((row + 1) % 3 == 0)
            cout << "+-------+-------+-------+" << endl;
    }
}

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE));
    cout << "Enter Sudoku board (9 values per row, 0 for empty):" << endl;

    for (int row = 0; row < SIZE; row++) {
    while (true) {
        cout << "Enter row " << row + 1 << " (exactly 9 numbers, use 0 for empty): ";
        string line;
        getline(cin >> ws, line);  // Read full line after skipping leading whitespaces

        stringstream ss(line);
        vector<int> tempRow;
        int val;
        while (ss >> val) {
            if (val < 0 || val > 9) {
                cout << "   Invalid value! Numbers must be between 0 and 9.\n";
                tempRow.clear();
                break;
            }
            tempRow.push_back(val);
        }

        if (tempRow.size() != SIZE) {
            cout << "    You must enter exactly 9 numbers!\n";
            continue;  // Retry this row
        }

        board[row] = tempRow;
        break;  // Valid row entered
    }
}


    cout << "\n Sudoku Before Solving:\n";
    printFancyBoard(board);

    if (solveSudoku(board)) {
        cout << "\n Sudoku Solved Successfully!\n";
        printFancyBoard(board);
    } else {
        cout << "\n No valid solution exists for this Sudoku.\n";
    }

    return 0;
}

