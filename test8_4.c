#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int get(int fd, long pos, char *buf, int n);
main()
{
    char buf[BUFSIZ];
    int n;
    int fd;
    long a = 1L;  //a:文件任意位置
    fd = open("000.txt",O_RDONLY,0);
    while ((n = get(fd,a,buf,BUFSIZ)) > 0){ 
        write(1, buf, n);
        a += BUFSIZ;
    }
    close(fd);
    return 0;
}
int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) >= 0)
        return read(fd, buf, n);
    else 
        return -1;
}