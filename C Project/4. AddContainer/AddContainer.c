//
//  AddContainer.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 13/10/21.
//

#include "AddContainer.h"
#include "PrintFloor.h"

/*
 Helper function that returns a 1 if the provided letter is found in the board, 0 otherwise
 Input:
    - floor array
    - letter to search for
 Output:
    - bool indicating if the provided letter is found in the board
 */
int SearchFloorForContainer(int floor[NUM_ROWS][NUM_COLS], int letter) {
    int found = 0;
    for (int i= 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (floor[i][j] == letter) {
                found = 1;
                break;
            }
        }
    }
    
    return found;
}

/*
 Adds a container to the board, with specified position, length, and direction
 Input:
    - floor array
    - size/length of the container to add (min 2)
    - direction the container is facing: 0 for horizontal, 1 for vertical
 */
void AddContainer(int floor[NUM_ROWS][NUM_COLS], int position, int size, int direction) {
    int currentLetter = 65;
    
    // searches for the next available letter in the board
    while (SearchFloorForContainer(floor, currentLetter)) {
        currentLetter++;
    }
    
    // converts position in to x and y values for the array
    int x = position % NUM_ROWS;
    int y = position / NUM_ROWS;
    
    if (direction) { // case one: if the container is aligned vertically
        // for loop to make sure the available space is vacant, and if not return immediately
        for (int i = 0; i < size; i++) {
            if (floor[y+i][x] != VACANT) {
                return;
            }
        }
        // identical for loop to actually add the container. nb, need two for loops because if the first check fails than cant add container
        for (int i = 0; i < size; i++) {
            floor[y+i][x] = currentLetter;
        }
    } else { // case two: if the container is aligned horizontally
        for (int i = 0; i < size; i++) {
            if (floor[y][x+i] != VACANT) {
                return;
            }
        }
        for (int i = 0; i < size; i++) {
            floor[y][x+i] = currentLetter;
        }
    }
}


void AddContainerAlt(int floor[NUM_ROWS][NUM_COLS], int position, int size, int direction) {
    int foundLetter = 1;
    char letter = 'A';
    int x = position % NUM_ROWS;
    int y = position / NUM_ROWS;
    int blocked = 0;
    
    // searches for the next available letter
    while (foundLetter) {
        foundLetter = 0;
        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COLS; j++) {
                if (floor[i][j] == letter) {
                    foundLetter = 1;
                    letter++;
                }
            }
        }
    }
    
    // decides whether there is space for the container
    if (direction) {
        for (int i = 0; i < size; i++) {
            if (floor[y+i][x] != VACANT) {
                blocked = 1;
                break;
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            if (floor[y][x+i] != VACANT) {
                blocked = 1;
                break;
            }
        }
    }
    
    // adds the container if there is space for it
    if (!blocked) {
        if (direction) {
            for (int i = 0; i < size; i++) {
                floor[y+i][x] = letter;
            }
        } else {
            for (int i = 0; i < size; i++) {
                floor[y][x+i] = letter;
            }
        }
    }
}
