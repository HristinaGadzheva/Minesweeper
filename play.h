#pragma once

#include<iostream>
#include "makeTurn.h"
#include "displayBoard.h"
#include "isOpenDigit.h"
#include "markBox.h"
#include "unmarkBox.h"

using namespace std;

const int MINES = 10;
const int COMMAND_SIZE = 7;

void play (char backBoard[SIZE][SIZE], char frontBoard[SIZE][SIZE])
{
    int row, col;
    bool gameOver = false;
    int movesLeft = SIZE * SIZE - MINES;
    int moveIndex = 0;
    char command[COMMAND_SIZE];

    while (!gameOver)
    {
        displayBoard (frontBoard);

        // validate cell
        do
        {
            cout << endl << "Select cell: ";
            cin >> row >> col;

            if ((row < MIN_VALID_INDEX || row > MAX_VALID_INDEX) || (col < MIN_VALID_INDEX || col > MAX_VALID_INDEX))
                cout << "Invalid cell. The cell indexes should be between 0 and 8." << endl;

            if (isOpenDigit (frontBoard, row, col))
                cout << "This cell is opened." << endl;

        } while (row < MIN_VALID_INDEX || row > MAX_VALID_INDEX || col < MIN_VALID_INDEX || col > MAX_VALID_INDEX || isOpenDigit (frontBoard, row, col));

        // validation comand
        do
        {
            cin.ignore (COMMAND_SIZE, '\n');
            cout << "Choose comand: open, mark or unmark: "; 
            cin.getline (command, COMMAND_SIZE);
            cout << endl;

            if (strcmp (command, "open") == 0)
            {
                if (isMine (backBoard, row, col))
                {
                    gameOver = true;
                    break;
                }

                gameOver = makeTurn (backBoard, frontBoard, row, col, &movesLeft);
            }
            else if (strcmp (command, "mark") == 0)
                markBox(frontBoard, row, col);
            else if (strcmp (command, "unmark") == 0)
                unmarkBox (frontBoard, row, col);
            else
                cout << "Invalid command!";

        } while (strcmp (command, "open") != 0 && strcmp (command, "mark") != 0 && strcmp (command, "unmark") != 0);

    }

    // check is won or lose
    if (movesLeft > 0)
    {
        cout << endl << "Game over! You hit an explosive. :( " << endl;
        displayBoard(backBoard);
        return;
    }
    else
    {
        cout << endl << "You won! :)" << endl;
        return;
    }

    // print frontBoard again
    displayBoard (frontBoard);
}