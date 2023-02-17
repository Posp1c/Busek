#include <stdio.h>
#include <math.h>

int main()
{
    // 1. zadani koeficientu a, b, c
    
    float a, b, c;
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);
    
    // 2. kontrola nenuloveho koeficientu a
    
    if (a == 0) {
        printf("Koeficient a nesmi byt nulovy!");
        return 0;
    }
    
    // 3. vypocet diskriminantu
    
    float D = -4*a*c + b*b;
    printf("D = %f\n", D);
    
    // 4. + 5. kontrola hodnoty diskriminantu a urceni reseni kvadraticke rovnice
    
    if (D > 0) {
        float x1 = (-b + sqrt(D))/(2*a);
        float x2 = (-b - sqrt(D))/(2*a);
        printf("x1 = %f\nx2 = %f", x1, x2);
    } else if (D == 0) {
        float x = (-b - sqrt(D))/(2*a);
        printf("x1,x2 = %f\n", x);
    } else {
        printf("Diskriminant vysel zaporny. Rovnice nema realne reseni.");
    }
    
    return 0;
}
