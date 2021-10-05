//
//  InitialiseFloor.h
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 5/10/21.
//

#ifndef InitialiseFloor_h
#define InitialiseFloor_h

#define NUM_ROWS 8
#define NUM_COLS 8

#define VACANT 0
#define BOUNDARY -1
#define ENTRY -2
#define EXIT -3

#include <stdio.h>
    
void InitialiseFloor(int floor[NUM_ROWS][NUM_COLS], char entryboundary, int index);

#endif
