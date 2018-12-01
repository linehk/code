#include <unistd.h>
/* #include "syscall.h" */

#define OPEN_MAX        20      /* max #files open at once */

typedef struct _iobuf {
        int cnt;        /* characters left */
        char *ptr;      /* next characters position */
        char *base;     /* location of buffer */
        int flag;       /* mode of file access */
        int fd;         /* file descriptor */
} FILE;
extern FILE _iob[OPEN_MAX];

enum _flags {
        _READ   = 01,   /* file open for reading */
        _WRITE  = 02,   /* file open for writing */
        _UNBUF  = 04,   /* file is unbuffered */
        _EOF    = 010,  /* EOF has occurred on this file */
        _ERR    = 020,  /* error occurred on this file */
};

/* fseek: seek with a file pointer */
int fseek(FILE *fp, long offset, int origin)
{
        unsigned nc;    /* # of chars to flush */
        long rc = 0;    /* return code */

        if (fp->flag & _READ) {
                if (origin == 1)        /* from current position? */
                        offset -= fp->cnt;      /* remember chars in buffer */
                rc = lseek(fp->fd, offset, origin);
                fp->cnt = 0;    /* no characters buffered */
        } else if (fp->flag & _WRITE) {
                if ((nc = fp->ptr - fp->base) > 0)
                        if (write(fp->fd, fp->base, nc) != nc)
                                rc = -1;
                if (rc != -1)   /* no errors yet? */
                        rc = lseek(fp->fd, offset, origin);
        }
        return (rc == -1) ? -1 : 0;
}