#include <stdlib.h>
#include <fcntl.h>
/* #include "syscall.h" */

/* calloc: allocate n objects of size size */
void *calloc(unsigned n, unsigned size)
{
        unsigned i, nb;
        char *p, *q;

        nb = n * size;
        if ((p = q = malloc(nb)) != NULL)
                for (i = 0; i < nb; i++)
                        *p++ = 0;
        return q;
}