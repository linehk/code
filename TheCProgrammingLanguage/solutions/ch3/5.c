/* itob: convert n to characters in s - base b */
void itob(int n, char s[], int b)
{
        int i, j, sign;
        void reverse(char s[]);

        if ((sign = n) < 0)     /* record sign */
                n = -n;         /* make n positive */
        i = 0;
        do {    /* generate digits in reverse order */
                j = n % b;      /* get next digit */
                s[i++] = (j <= 9) ? j+'0' :j +'a'-10;
        } while ((n /= b) > 0); /* delete it */
        if (sign < 0)
                s[i++] = '-';
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