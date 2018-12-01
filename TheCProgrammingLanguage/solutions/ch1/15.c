#include <stdio.h>

float celsius(float fahr);

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
   floating-point version */
main()
{
        float fahr;
        int lower, upper, step;

        lower = 0;              /* lower limit of temperature table */
        upper = 300;            /* upper limit */
        step = 20;              /* step size */

        fahr = lower;
        while (fahr <= upper) {
                printf("%3.0f %6.1f\n", fahr, celsius(fahr));
                fahr = fahr + step;
        }
}

/* celsius: convert fahr into celsius */
float celsius(float fahr)
{
        return (5.0/9.0) * (fahr-32.0);
}