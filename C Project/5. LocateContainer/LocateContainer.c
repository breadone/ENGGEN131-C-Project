//
//  5. LocateContainer.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 13/10/21.
//

#include "LocateContainer.h"

/*
 Locates a container on the board, and returns start and end position, and whether its blocked or not
 Input:
    - floor: 2d floor array
    - move: id (letter) of container to search for
    - rowStart/End: pointers for the row's start and end position
    - colStart/End: pointers for the column's start and end position
 Output:
    - boolean to determine if the container is stuck or not: 0 for not stuck, 1 for stuck
 */
int LocateContainer(int floor[NUM_ROWS][NUM_COLS], char move, int *rowStart, int *colStart, int *rowEnd, int *colEnd) {
    int stuck = 0;
    int found = 0;
    int direction = 0;
    
    // finds the start row/col position of the container
    for (int i = 0; i < NUM_ROWS && !found; i++) {
        for (int j = 0; j < NUM_COLS && !found; j++) {
            if (floor[i][j] == (int) move) {
                *rowStart = i; *colStart = j;
                *rowEnd = *rowStart; *colEnd = *colStart; // assigns end positions to start positions, since it counts length from start
                if (floor[i+1][j] == (int) move) {
                    direction = 1;
                }
                found = 1; // once the start of container has been found, need to exit both loops, so set bool to true
            }
        }
    }
    
    // finds end row/col of container and determines if its stuck or not
    int i = 0;
    if (direction) {
        while (floor[*rowStart + i][*colStart] == (int) move) {
            *rowEnd = *rowStart + i;
            i++;
        }
        stuck = ((floor[*rowStart - 1][*colStart] != VACANT) && (floor[*rowEnd + 1][*colStart] != VACANT)) ? 0 : 1;
    } else {
        while (floor[*rowStart][*colStart + i] == (int) move) {
            *colEnd = *colStart + i;
            i++;
        }
        stuck = ((floor[*rowStart][*colStart - 1] != VACANT) && (floor[*rowStart][*colEnd + 1] != VACANT)) ? 0 : 1;
    }
    
    return stuck;
}


int LocateContainerAlt(int floor[NUM_ROWS][NUM_COLS], char move, int *rowStart, int *colStart, int *rowEnd, int *colEnd) {
    int length = 1;
    int direction = 1;
    
    // finds the start of the container
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if ((char) floor[i][j] == move) {
                *rowStart = i;
                *colStart = j;
            }
        }
    }
    
    // decides direction of the contianer to make it easier
    if ((char) floor[*rowStart][*colStart+1] == move) {
        direction = 0;
    }
    
    if (direction) {
        while (floor[*rowStart+length][*colStart] == move) {
            *rowEnd = *rowStart + length;
            length++;
        }
    } else {
        while (floor[*rowStart][*colStart+length] == move) {
            *colEnd = *colStart + length;
            length++;
        }
    }
    
    
    
    return 0;
}
