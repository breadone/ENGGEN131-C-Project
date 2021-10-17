//
//  MoveContainer.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 13/10/21.
//

#include "MoveContainer.h"
#include "AddContainer.h"
#include "PrintFloor.h"

int MoveContainer(int floor[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1, int isBlocked) {
    int direction;
    int preferredDirection; // 1 for up/left, 0 for down/right
    int newStartPos;
    int containerLength;
    int result = 0;
    
    // decides the direction of the container
    direction = (c0 == c1) ? 1 : 0;
    // calculates the length of the container, does rely on the direction being known
    containerLength = (direction) ? r1 - r0 + 1 : c1 - c0 + 1;
    
    // decides what to return if the container is blocked
    if (!isBlocked && direction) {
        switch (floor[r0 - 1][c0]) {
            case ENTRY:
                return 1;
            case EXIT:
                return 2;
            default:
                break;
        }
        
        switch (floor[r1 + 1][c0]) {
            case ENTRY:
                return 1;
            case EXIT:
                return 2;
            default:
                break;
        }
        return -1;
    } else if (!isBlocked) {
        switch (floor[r0][c0 - 1]) {
            case ENTRY:
                return 1;
            case EXIT:
                return 2;
            default:
                break;
        }
        
        switch (floor[r0][c1 + 1]) {
            case ENTRY:
                return 1;
            case EXIT:
                return 2;
            default:
                break;
        }
        return -1;
    }
    
    /* decides which direction is unblocked,
     since we know its not blocked we can assume if the preferred direction is blocked, then the other direction is free */
    if (direction) {
        preferredDirection = (floor[r0 - 1][c0] == VACANT) ? 1 : 0;
    } else {
        preferredDirection = (floor[r0][c0-1] == VACANT) ? 1 : 0;
    }
    
    // moves the container
    if (direction && preferredDirection) { // vert container and moving up
        // finds the new start position of container
        newStartPos = r0;
        do {
            newStartPos--;
        } while (floor[newStartPos-1][c0] == VACANT);
        
        // removes the container from the floor
        for (int i = r0; i <= r1; i++) {
            floor[i][c0] = VACANT;
        }
        
        // adds the container back to the floor in the new position
        AddContainer(floor, (NUM_COLS * newStartPos + c0), containerLength, 1);
        
        switch (floor[newStartPos-1][c0]) {
            case ENTRY:
                result = 1;
                break;
            case EXIT:
                result = 2;
            default:
                break;
        }
    } else if (direction) { // vert container and moving down
        // finds the new start position of container
        newStartPos = r1;
        do {
            newStartPos++;
        } while (floor[newStartPos+containerLength][c0] == VACANT);
        
        // removes the container from the floor
        for (int i = r0; i <= r1; i++) {
            floor[i][c0] = VACANT;
        }
        
        // adds the container back to the floor in the new position
        AddContainer(floor, (NUM_COLS * newStartPos + c0), containerLength, 1);
        
        switch (floor[newStartPos+containerLength][c0]) {
            case ENTRY:
                result = 1;
                break;
            case EXIT:
                result = 2;
            default:
                break;
        }
        
    } else if (preferredDirection) { // horiz container and moving left
        newStartPos = c0;
        
        do {
            newStartPos--;
        } while (floor[r0][newStartPos-1] == VACANT);
        
        for (int i = c0; i <= c1; i++) {
            floor[r0][i] = VACANT;
        }
        
        AddContainer(floor, (NUM_COLS * r0 + newStartPos), containerLength, 0);
        
        switch (floor[r0][newStartPos-1]) {
            case ENTRY:
                result = 1;
                break;
            case EXIT:
                result = 2;
            default:
                break;
        }
    } else { // horiz container and moving right
        newStartPos = c1;
        
        do {
            newStartPos++;
        } while (floor[r0][newStartPos+containerLength] == VACANT);
        
        for (int i = c0; i <= c1; i++) {
            floor[r0][i] = VACANT;
        }
        
        AddContainer(floor, (NUM_COLS * r0 + newStartPos), containerLength, 0);
        
        switch (floor[r0][newStartPos+containerLength]) {
            case ENTRY:
                result = 1;
                break;
            case EXIT:
                result = 2;
            default:
                break;
        }
    }
    
    return result;
}

int MoveContainerAlt(int floor[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1, int isBlocked) {
    int result = 0;
    char direction = 'X'; // U D L R, for up, down, left, and right respectively
    int containerLetter = floor[r0][c0];
    int containerLength = 0;
    int headPos, tailPos;
    
    if (!isBlocked) { goto blocked; }
    
    if (c0 == c1) { // if c0 and c1 are the same, we know the container is oriented vertically
        direction = (floor[r0-1][c0] == VACANT) ? 'U' : 'D';
    } else {
        direction = (floor[r0][c0-1] == VACANT) ? 'L' : 'R';
    }
    
    // calculates the length of the container based on the direction
    containerLength = (direction == 'U' || direction == 'D') ? r1 - r0 + 1 : c1 - c0 + 1;
    
blocked:
    if (!isBlocked) {
        if (floor[r0-1][c0] == ENTRY ||
            floor[r1+1][c0] == ENTRY ||
            floor[r0][c0-1] == ENTRY ||
            floor[r0][c1+1] == ENTRY) {
            return 1;
        }
        
        if (floor[r0-1][c0] == EXIT ||
            floor[r1+1][c0] == EXIT ||
            floor[r0][c0-1] == EXIT ||
            floor[r0][c1+1] == EXIT) {
            return 2;
        }
    }
    
    // moves the container in the specified direction
    switch (direction) {
        case 'U':
            headPos = r0;
            tailPos = r1;
            do {
                floor[headPos-1][c0] = containerLetter;
                floor[tailPos][c0] = VACANT;
                headPos--; tailPos--;
            } while (floor[headPos-1][c0] == VACANT);
            result = floor[headPos-1][c0];
            break;
        case 'D':
            headPos = r1;
            tailPos = r0;
            do {
                floor[headPos+1][c0] = containerLetter;
                floor[tailPos][c0] = VACANT;
                headPos++; tailPos++;
            } while (floor[headPos+1][c0] == VACANT);
            result = floor[headPos+1][c0];
            break;
        case 'L':
            headPos = c0;
            tailPos = c1;
            do {
                floor[r0][headPos-1] = containerLetter;
                floor[r0][tailPos] = VACANT;
                headPos--; tailPos--;
            } while (floor[r0][headPos-1] == VACANT);
            result = floor[r0][headPos-1];
            break;
        case 'R':
            headPos = c1;
            tailPos = c0;
            do {
                floor[r0][headPos+1] = containerLetter;
                floor[r0][tailPos] = VACANT;
                headPos++; tailPos++;
            } while (floor[r0][headPos+1] == VACANT);
            result = floor[r0][headPos+1];
            break;
    }
    
    switch (result) {
        case ENTRY:
            return 1;
        case EXIT:
            return 2;
        default:
            return 0;
    }
}
