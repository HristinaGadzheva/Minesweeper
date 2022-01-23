#pragma once

// check is cell mine
bool isMine (char board[SIZE][SIZE], int row, int col)
{
    return board[row][col] == MINE;
}
