#include <unistd.h>


typedef long Align;

union header {
        struct {
                union header *ptr;
                unsigned size;
        } s;
        Align x;
};

typedef union header Header;

void free(void *);

/* bfree: free an arbitrary block p of n chars */
unsigned bfree(char *p, unsigned n)
{
        Header *hp;

        if (n < sizeof(Header))
                return 0;       /* too small to be useful */
        hp = (Header *)p;
        hp->s.size = n / sizeof(Header);
        free((void *)(hp+1));
        return hp->s.size;
}