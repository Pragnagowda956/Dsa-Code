#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[100], pattern[50];
    int i, j, flag;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    for(i = 0; i <= n - m; i++)
    {
        flag = 1;
        for(j = 0; j < m; j++)
        {
            if(text[i + j] != pattern[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("Pattern found at position %d\n", i + 1);
            break;
        }
    }

    if(!flag)
        printf("Pattern not found\n");

    fflush(stdout);          // flush output buffer
    system("getmac");        // works only on Windows

    return 0;
}