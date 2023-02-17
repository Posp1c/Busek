#include <stdio.h>

int main()
{
    // vyber cisla
    int n;
    printf("Zadej cislo: ");
    scanf("%i", &n);

    // menu
    char ch;
    printf("Vyber cyklus:\n");
    printf("\t(a) for\n");
    printf("\t(b) while\n");
    printf("\t(c) do-while\n");
    getchar();
    ch = getchar();
    
    // provedeni cyklu
    int i = 0;
    switch (ch) {
        case 'a':   // if (ch == 'a')
            for (i; i <= n; i = i + 2) {
                printf("%i,", i);
            }
            break;
        case 'b':   // else if (ch == 'b')
            while (i < n) {
                printf("%i,", i);
                //i = i + 2;
                i += 2;
            }
            break;
        case 'c':   // else if (ch == 'c')
            do {
                printf("%i,", i);
                i += 2;
            } while (i < n);
            break;
        default:    // else
            printf("Byla zadana spatna volba!\n");
    }

    return 0;
}
