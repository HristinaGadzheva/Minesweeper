#pragma once

#include "init.h"
#include "generateMines.h"
#include "fillBackBoard.h"
#include "play.h"

void playGround ()
{
    char frontBoard[SIZE][SIZE];
    char backBoard[SIZE][SIZE];

    init (backBoard, frontBoard);
    generateMines (backBoard, MINES);
    fillBackBoard (backBoard);
    play (backBoard, frontBoard);

    int command;

    do
    {
        cout << "Do you want to play again?" << endl << "1 - restart" << endl << "0 - exit" << endl;
        cin >> command;

        switch (command)
        {
        case 1: system ("cls");
            playGround ();
            break;
        case 0: exit (0);
        default:
            cout << "Command is Invalid! Input 1 for restart and 0 for exit.";
            break;
        }
    } while (command != 1 || command != 0);
}