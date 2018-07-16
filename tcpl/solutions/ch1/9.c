#include <stdio.h>

#define NONBLANK 'a';

/* replace string of blanks with a single blank */
main()
{
        int c, lastc;

        lastc = NONBLANK;
        while ((c = getchar()) != EOF) {
                if (c != ' ')
                        putchar(c);
                if (c == ' ')
                        if (lastc != ' ')
                                putchar(c);
                lastc = c;

                /*
                if (c != ' ')
                        putchar(c);
                else if (lastc != ' ')
                        putchar(c);
                lastc = c;
                */

                /*
                if (c != ' ' || lastc != ' ')
                        putchar(c);
                lastc = c;
                */
        }
}