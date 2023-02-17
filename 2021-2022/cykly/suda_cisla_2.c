#include <stdio.h>

int main() {
    int n;
    printf("Zadej cislo: ");
    scanf("%i", &n);

    printf("Vyber moznost:\n");
    printf("\t(1) for\n");
    printf("\t(2) while\n");
    printf("\t(3) do-while\n");
    
    int ch;
    scanf("%i", &ch);
    
    int i = 0;
    int b = 1;
    switch (ch) {
        case 1:     // if (ch == 1)
            for (i; i < n; i = i + 2) {
                if (b == 1) {
                    printf("%i", i);
                    b = 0;
                } else {
                    printf(",%i", i);
                }
            }
            break;
        case 2:     // else if (ch == 2)
            while (i < n) {
                printf("%i,", i);
                i += 2;
            }
            break;
        case 3:     // else if (ch == 3)
            do {
                printf("%i,", i);
                i += 2;
            } while (i < n);
            break;
        default:    // else
            printf("Zadal jsi spatnou volbu.\n");
    }

    return 0;
}
