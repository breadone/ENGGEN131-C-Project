//
//  testing.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 5/10/21.
//
#include <stdio.h>
#include "functions.h"
#include "constants.h"

int t_main(void) {
    int floor[NUM_ROWS][NUM_COLS];
    char moves[10] = "HCDEGHIA";
    int i, rowStart, colStart, rowEnd, colEnd, gameOver, isBlocked;
    InitialiseFloor(floor, 'R', 3);
    AddContainer(floor, 27, 2, 0);
    AddContainer(floor, 9, 2, 0);
    AddContainer(floor, 17, 3, 0);
    AddContainer(floor, 26, 2, 1);
    AddContainer(floor, 42, 2, 1);
    AddContainer(floor, 36, 2, 1);
    AddContainer(floor, 51, 3, 0);
    AddContainer(floor, 13, 3, 1);
    AddContainer(floor, 22, 2, 1);

    i = 0;
    PrintFloor(floor);
    while (moves[i] != '\0') {
    isBlocked = LocateContainer(floor, moves[i], &rowStart, &colStart, &rowEnd, &colEnd);
    gameOver = MoveContainer(floor, rowStart, colStart, rowEnd, colEnd, isBlocked);
    PrintFloor(floor);
    printf("Moved = %c; Game over = %d\n", moves[i], gameOver);
    i++;
    }
    return 0;
}


