//
//  testing.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 5/10/21.
//
#include <stdio.h>
#include "functions.h"
#include "constants.h"

int main(void) {
    int floor[NUM_ROWS][NUM_COLS];
    InitialiseFloorAlt(floor, 'T', 2);
    AddContainerAlt(floor, 9, 3, 0);
    AddContainerAlt(floor, 13, 5, 1);
    PrintFloor(floor);
    printf("Floor area available: %f\n", FloorAreaAvailable(floor, 10.5, 25.6));
    return 0;
}


