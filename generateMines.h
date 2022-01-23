#pragma once

#include<iostream>

const char MINE = '*';

void generateMines (char backBoard[SIZE][SIZE], int MINES)
{
    for (int i = 0; i < MINES; i++)
    {
        int randRow = rand () % SIZE; // generate random row
        int randCol = rand () % SIZE; // generate random col

        if (backBoard[randRow][randCol] == ' ')
            backBoard[randRow][randCol] = MINE;
        else
            --i;
    }
}
