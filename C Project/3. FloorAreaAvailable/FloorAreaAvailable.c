//
//  FloorAreaAvailable.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 12/10/21.
//

#include "FloorAreaAvailable.h"

/*
 calculates the area of VACANT spaces on the floor, using the length and width functions provided
 */
double FloorAreaAvailable(int floor[NUM_ROWS][NUM_COLS], double length, double width) {
    double area = 0;
    
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (floor[i][j] == VACANT) {
                area += (length * width);
            }
        }
    }
    
    return area;
}
