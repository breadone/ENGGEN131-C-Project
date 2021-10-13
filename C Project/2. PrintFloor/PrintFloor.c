//
//  PrintFloor.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 5/10/21.
//

#include "PrintFloor.h"
#include "constants.h"

void PrintFloor(int floor[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            
            switch (floor[i][j]) {
                case BOUNDARY:
                    printf("@");
                    break;
                case VACANT:
                    printf(" ");
                    break;
                case ENTRY:
                    printf("U");
                    break;
                case EXIT:
                    printf("X");
                    break;
            }
        }
        printf("\n");
    }
}
