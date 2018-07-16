#include <stdio.h>

/* count blanks, tabs, and newlines */
main()
{
        int c, nb, nt, nl;

        nb = 0;        /* number of blanks */
        nt = 0;        /* number of tabs */
        nl = 0;        /* number of newlines */
        while ((c = getchar) != EOF) {
                if (c == ' ')
                        ++nb;
                /* else if (c == '\t') */
                if (c == '\t')
                        ++nt;
                /* else if (c == '\n') */
                if (c == '\n')
                        ++nl;
        }
        printf("%d %d %d\n", nb, nt, nl);
}