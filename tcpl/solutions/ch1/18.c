#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);
int remove(char s[]);

/* remove trailing blanks and tabs, and delete blank lines */
main()
{
        char line[MAXLINE];     /* current input line */

        while (getline(line, MAXLINE) > 0)
                if (remove(line) > 0)
                        printf("%s", line);
        return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
        int c, i, j;

        j = 0;
        for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
                if (i < lim-2) {
                        s[j] = c;       /* line still in boundaries */
                        ++j;
                }
        if (c == '\n') {
                s[j] = c;
                ++j;
                ++i;
        }
        s[j] = '\0';
        return i;
}

/* remove trailing blanks and tabs from character string s */
int remove(char s[])
{
        int i;

        i = 0;
        while (s[i] != '\n')    /* find newline character */
                ++i;
        --i;                    /* back off from '\n' */
        while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
                --i;
        if (i >= 0) {           /* is it a nonblank line? */
                ++i;
                s[i] = '\n';    /* put newline character back */
                ++i;
                s[i] = '\0';    /* terminate the string */
        }
        return i;
}