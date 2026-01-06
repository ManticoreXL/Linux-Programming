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

int main(void) {

    char animal[20];
    char reason[32];

    printf("What's your favorite animal?: ");
    scanf("%s", animal);

    getchar();
    printf("Why do you like that animal?: ");
    fgets(reason, sizeof(reason), stdin);

    reason[strlen(reason) - 1] = '\0';

    printf("You like %s because it's %s.\n", animal, reason);

    return 0;
}