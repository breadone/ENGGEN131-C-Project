//
//  FloorAreaAvailable.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 12/10/21.
//

#include "FloorAreaAvailable.h"

double FloorAreaAvailable(int floor[NUM_ROWS][NUM_COLS], double length, double width) {
    double area = 0;
    
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (floor[i][j] == 0) {
                area += (length * width);
            }
        }
    }
    
    return area;
}
