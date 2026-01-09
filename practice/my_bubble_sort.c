/* 
This program sorts student in descending order of avg.


- Inputs:
    * Five students' informations

- Outputs:
    * Before/After sorting list
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <float.h>

#define LENGTH 5

typedef struct student {
    int num;
    char name[20];
    int kor, eng, math;
    double avg;
    char grade;
    
    struct student *next;
} Student;


void print_data(Student *s);
void sort_list(Student *s);
void swapper(Student *node1, Student *node2);


int main(void) {
   
    Student list[LENGTH];

    char temp[20];

    for (int i = 0; i < LENGTH; i++) {
        printf("--- Data Input at [%d] ---\n", i);

        printf("Insert student number: ");
        scanf("%d", &list[i].num);

        printf("Insert name: ");
        scanf("%s", temp);
        strcpy(list[i].name, temp);

        printf("Insert Korean, English, Math Score: ");
        scanf("%d %d %d", &list[i].kor, &list[i].eng, &list[i].math);

        double avg = (list[i].kor + list[i].eng + list[i].math) / 3;
        list[i].avg = avg;

        if (i == LENGTH - 1) {
            list[i].next = NULL;
        }
        else {
            list[i].next = &list[i + 1];
        }
    }

    printf("--- Before Sorting ---\n");
    print_data(list);

    sort_list(list);

    printf("--- After Sorting ---\n");
    print_data(list);
   
    return 0;
}


void print_data(Student *s) {
    Student *curr = s;

    while (curr != NULL) {
        printf("%d\t%s\t%d\t%d\t%d\t%.2lf\t%c\n", 
            curr->num,
            curr->name,
            curr->kor,
            curr->eng,
            curr->math,
            curr->avg,
            curr->grade
        );

        curr = curr->next;
    }
}


void sort_list(Student *s) {
    for (int i = 0; i < LENGTH - 1; i++) {
        for (int j = 0; j < LENGTH - 1 - i; j++) {
            if (s[j].avg < s[j + 1].avg) {
                swapper(&s[j], &s[j + 1]);
            }
        }
    }

    for (int i = 0; i < LENGTH; i++) {
        if (i == LENGTH - 1) {
            s[i].next = NULL;
        }
        else {
            s[i].next = &s[i + 1];
        }
    }
}

void swapper(Student *node1, Student *node2) {
    Student temp;

    temp = *node1;
    *node1 = *node2;
    *node2 = temp;
    return;
}