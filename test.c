/* 
This program


- Inputs:
    * 

- Outputs:
    * 
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <float.h>


typedef struct Position {
    int x;
    int y;
} Position;

void move(Position *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;

    return;
}


int main(void) {

    Position robot = {0, 0};

    printf("Start position: x=%d, y=%d\n", robot.x, robot.y);

    move(&robot, 5, 3);
    printf("After first move: x=%d, y=%d\n", robot.x, robot.y);

    move(&robot, -2, 4);
    printf("After second move: x=%d, y=%d\n", robot.x, robot.y);

    return 0;
}
