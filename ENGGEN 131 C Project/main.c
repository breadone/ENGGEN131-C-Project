//
//  main.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 5/10/21.
//
#include "InitialiseFloor.h"
#include <stdio.h>

int main(void) {
    int floor[NUM_ROWS][NUM_COLS];
    
    InitialiseFloor(floor, 'T', 2);
    
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", floor[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
