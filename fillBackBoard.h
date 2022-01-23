#pragma once

#include "convertFromIntToChar.h"
#include "getMinesCount.h"

void fillBackBoard (char backBoard[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (backBoard[i][j] != MINE)
            {
                int count = getMinesCount (backBoard, i, j); // get number of mines around the cell
                backBoard[i][j] = convertFromIntToChar (count);
            }
        }
    }
}
