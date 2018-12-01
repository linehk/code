#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/* #include "syscall.h" */

void error(char *fmt, ...);

/* cat: concatenate files - read / write / open / close */
main(int argc, char *argv[])
{
        int fd;
        void filecopy(int ifd, int ofd);

        if (argc == 1)  /* no args; copy standard input */
                filecopy(0, 1);
        else
                while (--argc > 0)
                        if ((fd = open(*++argv, O_RDONLY)) == -1)
                                error("cat: can't open %s", *argv);
                        else {
                                filecopy(fd, 1);
                                close(fd);
                        }
        return 0;
}

/* filecopy: copy file ifd to file ofd */
void filecopy(int ifd, int ofd)
{
        int n;
        char buf[BUFSIZ];

        while ((n = read(ifd, buf, BUFSIZ)) > 0)
                if (write(ofd, buf, n) != n)
                        error("cat: write error");
}