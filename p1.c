#include <stdio.h>
#include <stdlib.h>
int main() {
int m = (int)malloc(sizeof(int));
if (m) *m = 0; // Manual initialization
printf("malloc value: %d\n", *m);
free(m);
fflush(stdout);
system("getmac");
return 0;
}