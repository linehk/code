#define abs(x) ((x) < 0 ? -(x) : (x))

/* itoa: convert n to characters in s, w characters wide */
void iota(int n, char s[], int w)
{
        int i, sign;
        void reverse(char s[]);

        sign = n;       /* record sign */
        i = 0;
        do {
                s[i++] = abs(n % 10) + '0';     /* get next digit */
        } while ((n /= 10) != 0);       /* delete it */
        if (sign < 0)
                s[i++] = '-';
        while (i < w)   /* pad with blanks */
                s[i++] = ' ';
        s[i] = '\0';
        reverse(s);
}

/* reverse: reverse string s */
void reverse(char s[])
{
        int i, j;
        char temp;

        i = 0;
        while (s[i] != '\0') /* find the end of string */
                ++i;
        --i;                 /* back off from '\0' */
        if (s[i] == '\n')
                --i;         /* leave newline in place */
        j = 0;               /* beginning of new string */
        while (j < i) {
                temp = s[j];
                s[j] = s[i]; /* swap the characters */
                s[i] = temp;
                --i;
                ++j;
        }
}