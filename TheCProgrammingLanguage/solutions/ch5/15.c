#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMERIC 1       /* numeric sort */
#define DECR 2          /* sort in decreasing order */
#define FOLD 4          /* fold upper and lower cases */
#define LINES 100       /* max # of lines to be sorted */

int charcmp(char *, char *);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void qsort(char *v[], int left, int right,
        int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decr);

static char option = 0;

/* sort input line */
main(int argc, char *argv[])
{
        char *lineptr[LINES];   /* pointers to text lines */
        int nlines;     /* number of input lines read */
        int c, rc = 0;

        while (--argc > 0 && (*++argv)[0] == '-')
                while (c = *++argv[0])
                        switch (c) {
                        case 'f':       /* fold upper and lower cases */
                                option |= FOLD;
                                break;
                        case 'n':       /* number sort */
                                option |= NUMERIC;
                                break;
                        case 'r':       /* sort in decreasing order */
                                option |= DECR;
                                break;
                        default:
                                printf("sort: illegal option %c\n", c);
                                argc = 1;
                                rc = -1;
                                break;
                        }
        if (argc)
                printf("Usage: sort -fnr \n");
        else
                if ((nlines = readlines(lineptr, LINES)) > 0) {
                        if (option & NUMERIC)
                                qsort((void **)lineptr, 0, nlines-1,
                                        (int(*)(void *, void *))numcmp);
                        else if (option & FOLD)
                                qsort((void **)lineptr, 0, nlines-1,
                                        (int(*)(void *, void *))charcmp);
                        else
                                qsort((void **)lineptr, 0, nlines-1,
                                        (int(*)(void *, void *))strcmp);
                        writelines(lineptr, nlines, option & DECR);
                } else {
                        printf("input too big to sort \n");
                        rc = -1;
                }
        return rc;
}

/* charcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int charcmp(char *s, char *t)
{
        for ( ; tolower(*s) == tolower(*t); s++, t++)
                if (*s == '\0')
                        return 0;
        return tolower(*s) - tolower(*t);
}