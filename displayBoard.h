#pragma once

#include <iostream>

using namespace std;

// print frontBoard
void displayBoard (char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << '|' << ' ' << board[i][j] << ' ';
        }

        cout << '|' << endl;
    }
}
