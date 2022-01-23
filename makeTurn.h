#pragma once
#include "revealMines.h"
#include "isValidCell.h"
#include "isMine.h"

bool makeTurn (char backBoard[SIZE][SIZE], char frontBoard[SIZE][SIZE], int row, int col, int* movesLeft)
{
    if (frontBoard[row][col] != FILL) // cell is opened
        return false;

    if (backBoard[row][col] == MINE)
    {
        revealMines (backBoard, frontBoard); 
        return false;
    }
    else
    {
        frontBoard[row][col] = backBoard[row][col];

        // makes turn in all neighbour cells
        if (frontBoard[row][col] == ' ')
        {
            if (isValidCell (row - 1, col - 1) && !isMine (backBoard, row - 1, col - 1)) 
                makeTurn (backBoard, frontBoard, row - 1, col - 1, movesLeft);

            if (isValidCell (row - 1, col) && !isMine (backBoard, row - 1, col))
                makeTurn (backBoard, frontBoard, row - 1, col, movesLeft);

            if (isValidCell (row - 1, col + 1) && !isMine (backBoard, row - 1, col + 1))
                makeTurn (backBoard, frontBoard, row - 1, col + 1, movesLeft);

            if (isValidCell (row + 1, col + 1) && !isMine (backBoard, row + 1, col + 1))
                makeTurn (backBoard, frontBoard, row + 1, col + 1, movesLeft);

            if (isValidCell (row + 1, col) && !isMine (backBoard, row + 1, col))
                makeTurn (backBoard, frontBoard, row + 1, col, movesLeft);

            if (isValidCell (row + 1, col - 1) && !isMine (backBoard, row + 1, col - 1))
                makeTurn (backBoard, frontBoard, row + 1, col - 1, movesLeft);

            if (isValidCell (row, col - 1) && !isMine (backBoard, row, col - 1))
                makeTurn (backBoard, frontBoard, row, col - 1, movesLeft);

            if (isValidCell (row, col + 1) && !isMine (backBoard, row, col + 1))
                makeTurn (backBoard, frontBoard, row - 1, col + 1, movesLeft);
        }
    }

    return false;
}
