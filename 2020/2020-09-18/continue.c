# include <stdio.h>     /* printf, scanf */

int main () {
    int m = 0;
    for (int i = 0; i <= 20; i++) {
        if (i % 2) {
            continue;
        } else {
            m = i*i;
        }
        printf("%d\n", m);
    }

    return 0;
}