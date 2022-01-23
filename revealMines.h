#pragma once

// fill mines in frontBoard
void revealMines (char backBoard[SIZE][SIZE], char frontBoard[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (backBoard[i][j] == MINE)
            {
                frontBoard[i][j] = backBoard[i][j];
            }
        }
    }
}
