#include <stdio.h>
#include <ctype.h>

#define NUMBER  '0'     /* signal that a number was found */

int getch(void);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
        int c, i;
        static int lastc = 0;

        if (lastc == 0)
                c = getch();
        else {
                c = lastc;
                lastc = 0;
        }
        while ((s[0] = c) == ' ' || c == '\t')
                c = getch();
        s[1] = '\0';
        if (!isdigit(c) && c != '.')
                return c;       /* not a number */
        i = 0;
        if (isdigit(c)) /* collect integer part */
                while (isdigit(s[++i] = c = getch()))
                        ;
        if (c == '.')   /* collect fraction part */
                while (isdigit(s[++i] = c = getch()))
                        ;
        s[i] = '\0';
        if (c != EOF)
                lastc = c;
        return NUMBER;
}