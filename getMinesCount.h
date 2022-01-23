#pragma once

#include "isValidCell.h"

int getMinesCount (char backBoard[SIZE][SIZE], int row, int col)
{
    int count = 0;

    if (isValidCell (row - 1, col - 1) && backBoard[row - 1][col - 1] == MINE)
        count++;

    if (isValidCell (row - 1, col + 1) && backBoard[row - 1][col + 1] == MINE)
        count++;

    if (isValidCell (row + 1, col + 1) && backBoard[row + 1][col + 1] == MINE)
        count++;

    if (isValidCell (row + 1, col - 1) && backBoard[row + 1][col - 1] == MINE)
        count++;

    if (isValidCell (row - 1, col) && backBoard[row - 1][col] == MINE)
        count++;

    if (isValidCell (row, col - 1) && backBoard[row][col - 1] == MINE)
        count++;

    if (isValidCell (row + 1, col) && backBoard[row + 1][col] == MINE)
        count++;

    if (isValidCell (row, col + 1) && backBoard[row][col + 1] == MINE)
        count++;

    return count;
}
