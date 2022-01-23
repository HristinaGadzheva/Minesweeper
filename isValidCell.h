#pragma once

const int MIN_VALID_INDEX = 0;

bool isValidCell (int row, int col)
{
    return row >= MIN_VALID_INDEX && row < SIZE && col >= MIN_VALID_INDEX && col < SIZE;
}
