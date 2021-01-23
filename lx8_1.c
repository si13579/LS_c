#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdarg.h>
void error(char *fmt, ...);

main(int argc, char *argv[])
{
    int fd;
    void filecopy(int ifd, int ofd);

    if (argc == 1)
        filecopy(0, 1);
    else 
        while (--argc > 0) 
            if ((fd = open(*++argv, O_RDONLY)) == -1)
                error("cat: can't open %s", *argv);
            else {
                //printf("%s",*argv);
                filecopy(fd, 1);
                close(fd);
            }
    return 0;
}
void filecopy(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZ];

    while ((n = read(ifd, buf, BUFSIZ)) > 0)
        if (write(ofd, buf, n) != n)
            error("cat: write error");
}

void error(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}
