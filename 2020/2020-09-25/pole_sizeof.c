#include <stdio.h>

#define NUM 10

int main()
{
    float f[NUM];
    for (int i = 0; i < sizeof(f)/sizeof(f[0]); i++) {
        printf("%3.2f\n", f[i]);
    }
    
    int n = 13;
    printf("Datova velikost promenne int: %lu\n", sizeof(f)/sizeof(f[0]));
    return 0;
}
