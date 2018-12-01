/* strncpy: copy n characters from t to s */
void strncpy(char *s, char *t, int n)
{
        while (*t && n-- > 0)
                *s++ = *t++;
        while (n-- > 0)
                *s++ = '\0';
}

/* strncat: concatenate n characters of t to the end of s */
void strncat(char *s, char *t, int n)
{
        void strncpy(char *s, char *t, int n);
        int strlen(char *);

        strncpy(s+strlen(s), t, n);
}

/* strncmp: compare at most n characters of t with s */
int strncmp(char *s, char *t, int n)
{
        for ( ; *s == *t; s++, t++)
                if (*s == '\0' || --n <= 0)
                        return 0;
        return *s - *t;
}