#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int result = strcmp(str1, str2);  // built-in function

    if(result == 0)
        printf("Strings are equal\n");
    else if(result < 0)
        printf("First string is smaller than second string\n");
    else
        printf("First string is greater than second string\n");

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}