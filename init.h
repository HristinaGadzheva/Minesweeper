#pragma once

const int SIZE = 9;
const char FILL = '#';

// fill backBoard and frontBoard
void init (char backBoard[][SIZE], char frontBoard[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            backBoard[i][j] = ' ';
            frontBoard[i][j] = FILL;
        }
    }
}
