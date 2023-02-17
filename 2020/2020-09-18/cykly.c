# include <stdio.h>     /* printf */

int main () {
    // program vypisuje cisla 1 az 10 pomoci ruznych cyklu
    
    /* FOR */
    printf("FOR #1\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }
    printf("FOR #2\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i + 1);
    }
    
    /* WHILE */
    printf("WHILE #1\n");
    int j = 1;
    while (j <= 10) {
        printf("%d\n", j);
        ++j;
    }
    printf("WHILE #2\n");
    int k = 1;
    while (k <= 10) {
        printf("%d\n", k++);
    }
    
    /* DO-WHILE */
    printf("DO-WHILE #1\n");
    int l = 1;
    do {
        printf("%d\n", l++);
    } while (l <= 10);
    //printf("%d\n", l);
    printf("DO-WHILE #2\n");
    int m = 0;
    do {
        printf("%d\n", ++m);
    } while (m < 10);
    //printf("%d\n", m);

    return 0;
}