#include <string.h>

#define MAXLEN 1000 /* maximum length of line */
#define MAXSTOR 5000    /* size of available storage space */

int getline(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
        int len, nlines;
        char line[MAXLEN];
        char *p = linestor;
        char *linestop = linestor + MAXSTOR;

        nlines = 0;
        while ((len = getline(line, MAXLEN)) > 0)
                if (nlines >= maxlines || p+len > linestop)
                        return -1;
                else {
                        line[len-1] = '\0';     /* delete newline */
                        strcpy(p, line);
                        lineptr[nlines++] = p;
                        p += len;
                }
        return nlines;
}