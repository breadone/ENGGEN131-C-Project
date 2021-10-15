//
//  MoveContainer.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 13/10/21.
//

#include "MoveContainer.h"
#include "AddContainer.h"

int MoveContainer(int floor[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1, int isBlocked) {
    int direction = 0;
    int preferredDirection; // 1 for up/left, 0 for down/right
    int newStartPos;
    
    if (!isBlocked) { return 0; } // if the container is blocked no point in continuing
    if (c0 == c1) { direction = 1; } // decides the direction of the container
    
    /* decides which direction is unblocked,
     since we know its not blocked we can assume if the preferred direction is blocked, then the other direction is free */
    if (direction) {
        preferredDirection = (floor[r0 - 1][c0] == VACANT) ? 1 : 0;
    } else {
        preferredDirection = (floor[r0][c0-1] == VACANT) ? 1 : 0;
    }
    
    // moves the container
    if (direction && preferredDirection) { // vert and up
        // finds the new start position of container
        newStartPos = r0;
        for (int i = r0; i != VACANT; i--) {
            newStartPos--;
            
        } /// this is prob the issue lol wtf is this
        for (int i = r0; i <= r1; i++) {
            floor[i][c0] = VACANT;
        }
        AddContainer(floor, (NUM_COLS * r0 + c0), (r1-r0), 1);
    } else if (direction) { // vert and down
        
    } else if (preferredDirection) { // horiz and left
        
    } else { // horiz and right
        
    }
    
    return 0;
}
