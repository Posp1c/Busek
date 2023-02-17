# include <stdio.h>     /* printf, scanf */

int main () {
    int c;
    int e = 0;
    while (e != 1) {
        printf("Zadej cislo: ");
        scanf("%d", &c);
        switch (c) {
            case 0:
                printf("NE\n");
                break;
            case 1:
                printf("ANO\n");
                break;
            case 9:
                printf("Program ukoncen!\n");
                e = 1;
                break;
            default:
                printf("Neznamy prikaz!\n");
                break;
        }
    }

    return 0;
}