#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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

/* _flushbuf: allocate and flush output buffer */
int _flushbuf(int x, FILE *fp)
{
        unsigned nc;    /* # of chars to flush */
        int bufsize;    /* size of buffer alloc. */

        if (fp < _iob || fp >= _iob + OPEN_MAX)
                return EOF;     /* error: invalid pointer */
        if ((fp->flag & (_WRITE | _ERR)) != _WRITE)
                return EOF;
        bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
        if (fp->base == NULL) { /* no buffer yet */
                if ((fp->base = (char *)malloc(bufsize)) == NULL) {
                        fp->flag |= _ERR;
                        return EOF;     /* can't get buffer */
                }
        } else {
                nc = fp->ptr - fp->base;
                if (write(fp->fd, fp->base, nc) != nc) {
                        fp->flag |= _ERR;
                        return EOF;     /* error: return EOF */
                }
        }
        fp->ptr = fp->base;     /* beginning of buffer */
        *fp->ptr++ = (char)x;   /* save current char */
        fp->cnt = bufsize - 1;
        return x;
}

/* fclose: close file */
int fclose(FILE *fp)
{
        int rc; /* return code */

        if ((rc = fflush(fp)) != EOF) { /* anything to flush? */
                free(fp->base);
                fp->ptr = NULL;
                fp->cnt = 0;
                fp->base = NULL;
                fp->flag &= ~(_READ | _WRITE);
        }
        return rc;
}

/* fflush: flush buffer associated with file fp */
int fflush(FILE *fp)
{
        int rc = 0;

        if (fp < _iob || fp >= _iob + OPEN_MAX)
                return EOF;     /* error: invalid pointer */
        if (fp->flag & _WRITE)
                rc = _flushbuf(0, fp);
        fp->ptr = fp->base;
        fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
        return rc;
}