#pragma once
#include "convertFromIntToChar.h"

const int  MAX_VALID_INDEX = SIZE - 1;

// is open cell with digit
bool isOpenDigit (char frontBoard[SIZE][SIZE], int row, int col)
{
    return frontBoard[row][col] >= convertFromIntToChar (MIN_VALID_INDEX) && frontBoard[row][col] <= convertFromIntToChar (MAX_VALID_INDEX);
}