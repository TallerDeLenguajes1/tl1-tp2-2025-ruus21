#define N 20
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
int i;
int *punt;
for(i = 0;i<N; i++)
{
punt = 1+rand()%100;
printf("[%d]: %d\n ", i, punt);
}

return 0;
}

