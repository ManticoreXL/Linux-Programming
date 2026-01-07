/* 
This program generates 2D grid that fills cells with sequential values and aggregates sums.

- Inputs:
    * The number of columns and rows for the grid.

- Outputs:
    * A formatted 2D array where the last row and column act as totals for the preceding values.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


int main(void) {

    int cols, rows;
    scanf("%d %d", &cols, &rows);

    // Define 2 dimensional list of int
    int **list = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        list[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize the list
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            list[i][j] = 0;


    int value = 1;

    // Insert value into the list
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols - 1; j++) {
            list[i][j] = value;
            list[rows - 1][j] += value;
            list[i][cols - 1] += value;
            list[rows - 1][cols - 1] += value;
            value++;
        }
    }

    // Print the result
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d", list[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(list[i]);
    }
    free(list);

    return 0;
}