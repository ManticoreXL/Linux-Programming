/* 
This program determines sensor value by threshold.

- Inputs:
    * Total numbers of sensors
    * Sensor value
    * Threshold value

- Outputs:
    * Determined labels by threshold
    * Total numbers of counted as black
    * Calculated average of index
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int process_value(const int value[], int label[], int n, int threshold);
double get_average(const int label[], int n, int count);

int main(void) {

    int n;
    int *value, *label;
    int threshold;
    int count = 0;
    int sum = 0;
    double avg;

    // Get n
    printf("Insert total numbers of sensor record: ");
    scanf("%d", &n);

    value = (int*)malloc(sizeof(int) * n + 1);
    label = (int*)malloc(sizeof(int) * n + 1);

    if (value == NULL || label == NULL) {
        printf("Failed to allocate memory\n");
        return 0;
    }

    // Get value[i]
    for (int i = 0; i < n; i++) {
        printf("Value at %d: ", i);
        scanf("%d", &value[i]);
    }

    // Call value processor function
    count = process_value(value, label, n, threshold);

    // Calculate average of index
    avg = get_average(label, n, count);

    printf("---Results---\n");
    for (int i = 0; i < n; i++) {
        printf("label[%d]: %d\n", i, label[i]);
    }
    printf("Black count: %d\n", count);
    printf("Average of index: %lf\n", avg);

    return 0;
}

int process_value(const int value[], int label[], int n, int threshold) {
    
    if(value == NULL || label == NULL) {
        printf("Value Error: process_value()\n");
        return -1;
    }

    int count = 0;

    // Get threshold
    printf("Insert threshold value: ");
    scanf("%d", &threshold);

    // Determine sensor value by the threshold
    for (int i = 0; i < n; i++) {
        if (value[i] >= threshold) { // count as black
            label[i] = 1;
            count++;
        }
        else { // count as non-black
            label[i] = 0;
        }
    }

    return count;
}

double get_average(const int label[], int n, int count) {
    if (label == NULL) {
        printf("NULL POINTER: get_average()\n");
        return -1;
    }

    int sum = 0;
    double avg;

    // Calculate average of index
    for (int i = 0; i < n && count != 0; i++) {
        sum += i * label[i];
    }
    avg = (double)sum / count;

    return avg;
}