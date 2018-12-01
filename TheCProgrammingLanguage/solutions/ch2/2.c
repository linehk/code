/*

for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;

replace to:

enum loop { NO, YES};
enum loop okloop = YES;

i = 0;
while (okloop == YES)
        if (i >= lim-1) // outside of valid range?
                okloop = NO;
        else if ((c = getchar()) == '\n')
                okloop = NO;
        else if (c == EOF)       // end of file?
                okloop = NO;
        else {
                s[i] = c;
                ++i;
        }
*/