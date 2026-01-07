/* 
My string copy, n copy, concatenation, n concatenation, length, compare.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


void my_strcpy(char *dest, const char *src);
void my_strncpy(char *dest, const char *src, int n);
void my_strcat(char *dest, const char *src);
void my_strncat(char *dest, const char *src, int n);
int my_strlen(const char *str);
int my_strcmp(const char *str1, const char *str2);


void my_strcpy(char *dest, const char *src) {
    if (dest == NULL || src == NULL) {
        printf("Error: my_strcpy() - param (dest || src) is NULL.\n");
        return;
    }

    int i = 0;
    
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';    
}


void my_strncpy(char *dest, const char *src, int n) {
    if (dest == NULL || src == NULL) {
        printf("Error: my_strcpy() - param (dest || src) is NULL.\n");
        return;
    }

    int i = 0;
    
    while (src[i] != '\0' && i <= n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';    
}


void my_strcat(char *dest, const char *src) {
    if (dest == NULL || src == NULL) {
        printf("Error: my_strcpy() - param (dest || src) is NULL.\n");
        return;
    }

    int i = 0, j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0') 
        dest[i++] = src[j++];
    
    dest[i] = '\0';
}


void my_strncat(char *dest, const char *src, int n) {
    if (dest == NULL || src == NULL) {
        printf("Error: my_strcpy() - param (dest || src) is NULL.\n");
        return;
    }

    int i = 0, j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j <= n) 
        dest[i++] = src[j++];
    
    dest[i] = '\0';
}


int my_strlen(const char *str) {
    if (str == NULL) {
        printf("Error: my_strlen() - param str is NULL.\n");
        return -1;
    }

    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}


int my_strcmp(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        printf("Error: my_strcmp() - param (str1 || str2) is NULL.\n");
        return -1;
    }

    int i = 0;

    while (str1[i] != '\0' && str1[i] == str2[i])
        i++;

    return (unsigned char)str1[i] - (unsigned char)str2[i];
}


int main(void) {

    char str1[32] = "Hello, world!";
    char str2[32] = "... And my friend!";

    char mstrcpy[32] = "";
    char mstrncpy[32] = "";
    char mstrcat[32] = "";
    char mstrncat[32] = "";

    my_strcpy(mstrcpy, str1);
    printf("my_strcpy(): %s\n", mstrcpy);

    my_strncpy(mstrncpy, str1, 5);
    printf("my_strncpy(): %s\n", mstrncpy);

    my_strcat(mstrcat, str1);
    my_strcat(mstrcat, str2);
    printf("my_strcat(): %s\n", mstrcat);

    my_strncat(mstrncat, str1, 5);
    my_strncat(mstrncat, str2, 5);
    printf("my_strncat(): %s\n", mstrncat);

    printf("my_strlen(): %d\n", my_strlen(str1));
    
    printf("my_strcmp(): %d\n", my_strcmp(str1, str2));

    return 0;
}