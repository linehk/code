/* isupper: return 1 (true) if c is an upper case letter */
int isupper(char c)
{
        if (c >= 'A' && c <= 'Z')
                return 1;
        else
                return 0;
}

// another solution:
#define isupper(c) ((c) >= 'A' && (c) <= 'Z') ? 1 : 0