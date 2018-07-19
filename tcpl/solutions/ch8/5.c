#include <stdio.h>
#include <string.h>
#include <fcntl.h>      /* flags for read and write */
#include <sys/types.h>  /* typedefs */
#include <sys/stat.h>   /* structure returned by stat */
#include "dirent.h"

int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

/* fsize: print inode #, mode, links, size of file "name" */
void fsize(char *name)
{
        struct stat stbuf;

        if (stat(name, &stbuf) == -1) {
                fprintf(stderr, "fsize: can't access %s\n", name);
                return;
        }
        if ((stbuf.st_mode & __S_IFMT) == __S_IFDIR)
                dirwalk(name, fsize);
        printf("%5u %6o %3u %8ld %s\n", stbuf.st_ino,
                stbuf.st_mode, stbuf.st_nlink, stbuf.st_size, name);
}