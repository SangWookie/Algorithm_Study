#include <iostream>
using namespace std;

bool promising(int sudoku[10][10], int row, int col, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == val && i != col)
            return false;

        if (sudoku[i][col] == val && i != row)
            return false;
    }
    for (int i = row - row % 3; i < row - row % 3 + 3; i++)
    {
        for (int j = col - col % 3; j < col - col % 3 + 3; j++)
        {
            if (sudoku[i][j] == val &&
                (i != row && j != col))
                return false;
        }
    }
    return true;
}

void printSudoku(int sudoku[10][10])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j];
        }
        cout << '\n';
    }
}

void solveSudoku(int sudoku[10][10], int blankCnt)
{
    if (blankCnt == 0)
    {
        printSudoku(sudoku);
        exit(0);
    }

    int thisSudoku[10][10];
    copy(&sudoku[0][0], &sudoku[0][0] + 100, &thisSudoku[0][0]);

    // find first 0(blank)
    int blankRow = -1, blankCol = -1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (thisSudoku[i][j] == 0)
            {
                blankRow = i;
                blankCol = j;
                break;
            }
        }
        if (blankRow != -1)
            break;
    }

    for (int i = 1; i < 10; i++)
    {
        if (promising(thisSudoku, blankRow, blankCol, i))
        {
            thisSudoku[blankRow][blankCol] = i;
            solveSudoku(thisSudoku, blankCnt - 1);
        }
    }
}

int main()
{
    char input[10][10];
    int sudoku[10][10];
    for (int i = 0; i < 9; i++)
    {
        cin >> input[i];
    }

    int blankCnt = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sudoku[i][j] = input[i][j] - '0';
            if (sudoku[i][j] == 0)
                blankCnt++;
        }
    }

    solveSudoku(sudoku, blankCnt);
}