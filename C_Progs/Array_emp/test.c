#include <stdio.h>

int main() {
    long double pi = 3.14159265358979323846L; // 'L' suffix for long double literal

    printf("Size of long double: %zu bytes\n", sizeof(long double));


    printf("Long double in decimal: %Lf\n", pi);
    printf("Long double in scientific (lowercase e): %Le\n", pi);
    printf("Long double in scientific (uppercase E): %LE\n", pi);
    printf("Long double in hexadecimal: %La\n", pi);

    long double input_val;
    printf("Enter a long double value: ");
    scanf("%Lf", &input_val); // Note the '&' for input
    printf("You entered: %Lf\n", input_val);

    return 0;
}
