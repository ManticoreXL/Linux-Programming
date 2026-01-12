#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <float.h>

#define IPV4 32
#define IPV6 40

typedef struct address {
    char addr[40];
    int count;
} addr;

int main(void) {
    
    FILE *fp;

    int ping_count = 0;
    int addr_amount = 0;
    int size = 64;
    int len;

    char buf[512];
    char *token;
    char *address;

    int most_count = 0;
    int most_index = -1;

    addr *temp;
    addr *list = malloc(sizeof(addr) * size);

    if (list == NULL) {
        printf("[ERRPR] Failed to allocate memory to list.\n");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        list[i].count = 0;
    }

    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("[ERROR] Failed to open log.txt.\n");
        return -1;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        // dispose useless part
        token = strtok(buf, " ");
        for (int i = 0; i < 12; i++) {
            token = strtok(NULL, " ");
        }

        // insert address into list
        char address[64];
        strcpy(address, token);

        for (int i = 63; i > 38; i--) {
            if (address[i] == ':')
                address[i] = '\0';
            else
                address[i] = 0;
        }

        for (int i = 0; i < ping_count; i++) {
            if (list[i].count == 0) {
                strcpy(list[i].addr, address);
                list[i].count++;
                addr_amount++;
                break;
            }
            else if (strcmp(list[i].addr, address) == 0) {
                list[i].count++;
                break;
            }
        }

        ping_count++;        
    }

    for (int i = 0; i < addr_amount; i++) {
        if (list[i].count > most_count) {
            most_index = i;
            most_count = list[i].count;
        }
    }

    printf("Most frequently called address: %s\n", list[most_index].addr);
    printf("Count: %d\n", list[most_index].count);

    free(list);
    fclose(fp);

    return 0;
}