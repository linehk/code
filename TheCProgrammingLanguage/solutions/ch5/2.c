#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getfloat: get next floating-point number from input */
int getfloat(float *pn)
{
        int c, sign;
        float power;

        while (isspace(c = getch()))    /* skip white space */
                ;
        if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
                ungetch(c);     /* it's not a number */
                return 0;
        }
        sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-')
                c = getch();
        for (*pn = 0.0; isdigit(c); c = getch())
                *pn = 10.0 * *pn + (c - '0');   /* integer part */
        if (c == '.')
                c = getch();
        for (power = 1.0; isdigit(c); c = getch()) {
                *pn = 10.0 * *pn + (c - '0');   /* fractional part */
                power *= 10.0;
        }
        *pn *= sign / power;    /* final number */
        if (c != EOF)
                ungetch(c);
        return c;
}