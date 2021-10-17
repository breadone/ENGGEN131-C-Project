//
//  MoveContainer.h
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 13/10/21.
//

#ifndef MoveContainer_h
#define MoveContainer_h

#include <stdio.h>
#include "constants.h"
int MoveContainer(int floor[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1, int isBlocked);
int MoveContainerAlt(int floor[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1, int isBlocked);

#endif /* MoveContainer_h */
