//
//  InitialiseFloor.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 5/10/21.
//

#include "InitialiseFloor.h"
/*
InitialiseFloor takes a 2D array and initialises it to fit with the rules of the game, with boundary, vacant, entry, and exit points
Input:
    - floor: the 2d array to be modified
    - entryboundary: either T, B, L, R, to decide which wall the entry point will be
    - index: how far along the chosen wall the entry will be
 */
void InitialiseFloor(int floor[NUM_ROWS][NUM_COLS], char entryboundary, int index) {
    // STEP ONE: initialise boundaries
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            // condition one: if the current element is on the bottom or top row of the array
            if (i == 0 || i == NUM_ROWS-1) {
                floor[i][j] = BOUNDARY;
                continue;
            }
            
            // else: if element is at the left or rightmost side, then boundary, else vacant
            if (j == 0 || j == NUM_COLS-1) {
                floor[i][j] = BOUNDARY;
            } else {
                floor[i][j] = VACANT;
            }
        }
    }
    
    // STEP TWO: add entry and exit
    switch (entryboundary) {
        case 'T':
            floor[0][index] = ENTRY;
            floor[NUM_ROWS-1][index] = EXIT;
            break;
        case 'B':
            floor[NUM_ROWS-1][index] = ENTRY;
            floor[0][index] = EXIT;
            break;
        case 'L':
            floor[index][0] = ENTRY;
            floor[index][NUM_COLS-1] = EXIT;
            break;
        case 'R':
            floor[index][NUM_COLS-1] = ENTRY;
            floor[index][0] = EXIT;
            break;
        default:
            break;
    }
}

void InitialiseFloorAlt(int floor[NUM_ROWS][NUM_COLS], char entryboundary, int index) {
    // do top row
    for (int i = 0; i < NUM_COLS; i++) {
        floor[0][i] = BOUNDARY;
    }
    
    // do middle stuff
    for (int i = 1; i < NUM_ROWS-1; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            floor[i][j] = VACANT;
            
            // make right or left side the boundary
            if (j == 0 || j == NUM_COLS - 1) {
                floor[i][j] = BOUNDARY;
            }
        }
    }
    
    // do bottom row
    for (int i = 0; i < NUM_COLS; i++) {
        floor[NUM_ROWS-1][i] = BOUNDARY;
    }
    
    switch (entryboundary) {
        case 'T':
            floor[0][index] = ENTRY;
            floor[NUM_ROWS-1][index] = EXIT;
            break;
        case 'B':
            floor[NUM_ROWS-1][index] = ENTRY;
            floor[0][index] = EXIT;
            break;
        case 'L':
            floor[index][0] = ENTRY;
            floor[index][NUM_COLS-1] = EXIT;
            break;
        case 'R':
            floor[index][NUM_COLS-1] = ENTRY;
            floor[index][0] = EXIT;
            break;
        default:
            break;
    }
}
