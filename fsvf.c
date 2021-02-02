#include <fcntl.h>
#include <stdlib.h>

#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20
#define PERMS 0666
#define SEEK_SET 0//标准库中表示偏移起始位置为文件头
#define SEEK_CUR 1//标准库中表示偏移起始位置为当前位置
#define SEEK_END 2//标准库中表示偏移起始位置为文件尾

struct flags{
	unsigned int _READ  : 1;//只读
	unsigned int _WRITE : 1;//只写
	unsigned int _UNBUF : 1;//无缓冲
	unsigned int _EOF   : 1;//文件结尾
	unsigned int _ERR   : 1;//错误
};

typedef struct _iobuf{
	int cnt;   //缓冲区剩余字符数
	char *ptr; //指向缓冲区下一字符的指针
	char *base;//指向缓冲区首字符的指针
	struct flags flag;//文件模式
	int fd;//文件描述符
} FILE;

FILE _iob[OPEN_MAX] = {
    {0, (char *) 0, (char *) 0, {1, 0, 0, 0, 0}, 0},//stdin，只读形式
    {0, (char *) 0, (char *) 0, {0, 1, 0, 0, 0}, 1},//stdout，只写形式
    {0, (char *) 0, (char *) 0, {0, 1, 1, 0, 0}, 2},//stderr，无缓冲写入形式
};

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])



#define feof(p) ((p) -> flag._EOF != 0)
#define ferror(p) ((p) -> flag._ERR != 0)
#define fileno(p) ((p) -> fd)

#define getc(p) (--(p) -> cnt >= 0     \
? (unsigned char) *(p) -> ptr++ : _fillbuf(p))
//刚开始执行时，缓冲区剩余字符数为0，调用_fillbuf将文件中的数据读取到缓冲区，然后每次返回一个字符

#define putc(x, p) (--(p) -> cnt >= 0    \
? *(p) -> ptr++ = (x) : _flushbuf((x), p))
//刚开始执行时，缓冲区剩余字符为0时，调用_flushbuf分配缓冲区，然后每次写入一个字符到缓冲区，直到cnt为0，
//调用_flushbuf将缓冲区字符写入文件中

//getc和putc的区别在于：getc是调用_fillbuf将文件中的数据读取到缓冲区，然后每次从缓冲区返回一个字符
//putc是先将字符写入缓冲区，然后调用_flushbuf将缓冲区的数据写入文件

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

FILE *fopen(const char *, const char *);

int _fillbuf(FILE *);//_fillbuf填充缓冲区，将文件的数据读取到缓冲区中

int _flushbuf(int, FILE *);//_flushbuf冲刷缓冲区，将缓冲区的数据写入到参数指定的文件中

int fflush(FILE *);//fflush函数强迫将缓冲区内的数据写回参数指定的文件中，如果参数为NULL，fflush()会将所有打开的文件数据更新

int fclose(FILE *);//fclose函数关闭一个文件流，并释放文件指针和相关的缓冲区

int fseek(FILE *, long, int);


int main()
{
	 int a;
    //FILE *fp1;
//    FILE *fp2;
    //fp1 = fopen("000.txt","r");
  //  fp2 = fopen("0888.txt","w");
    //a = getc(fp1);
    //putchar(a);
    //fclose(fp1);
    //fclose(fp2);
    a = getchar();
    putchar(a);
	return 0;

}

FILE *fopen(const char *name, const char *mode)
{
	int fd;
	FILE *fp;

	
	if(*mode != 'r' && *mode != 'w' && *mode != 'a')//没有以指定模式打开文件
		return NULL;
	for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if(fp -> flag._READ == 0 && fp -> flag._WRITE == 0)//在结构数组中查找有无未赋值的成员
			break;

	if(fp >= _iob + OPEN_MAX)//如果遍历结构数组未找到未赋值成员
		return NULL;
	
	if(*mode == 'w')//以只写形式打开文件
		fd = creat(name, PERMS);//creat函数新建一个文件或者将现有文件长度截为0
	else if(*mode == 'a')//以写的形式打开文件在文件末尾添加内容
	{
		if((fd = open(name, O_RDONLY, 0)) == -1)//没有该文件
			fd = creat(name, PERMS);//新建文件
		lseek(fd, 0L, 2);//定位到文件结尾
	}
	else//以只读形式打开文件
		fd = open(name, O_RDONLY, 0);

	if(fd == -1)//文件打开或者新建失败
		return NULL;
	fp -> fd = fd;
	fp -> cnt = 0;
	fp -> base = NULL;
	fp -> flag._READ = (*mode == 'r') ? 1 : 0;//标注该文件以哪种模式打开
	fp -> flag._WRITE = (*mode == 'r') ? 0 : 1;
	
	return fp;
}

int _fillbuf(FILE *fp)
{
	int bufsize;

	if(fp -> flag._READ == 0 || fp -> flag._EOF == 1 || fp -> flag._ERR == 1)//文件不是以只读形式打开或到文件结尾或遇到错误
		return EOF;
	
	bufsize = (fp -> flag._UNBUF) ? 1 : BUFSIZ;//如果是无缓冲，则缓冲区大小为1，否则为BUFSIZ
	
	if(fp -> base == NULL)//如果此前未分配缓冲区
		if((fp -> base = (char *) malloc(bufsize)) == NULL)//如果分配缓冲区内存失败
			return EOF;

	fp -> ptr = fp -> base;//ptr指向缓冲区首字符
	fp -> cnt = read(fp -> fd, fp -> ptr, bufsize);//read函数从文件中最大读取bufsize个字符到缓存区，并返回实际读取字符数
	if(--fp -> cnt < 0)//如果实际读取字符数量小于等于0
	{
		if(fp -> cnt == -1)//实际读取为0时，说明遇到文件结尾
			fp -> flag._EOF = 1;
		else//实际读取为负值时，说明遇到文件错误
			fp -> flag._ERR = 1;
		fp -> cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp -> ptr++;//返回缓冲区首字符，ptr指向缓冲区下一字符
}

int _flushbuf(int c, FILE *fp)
{
	int bufsize;
	int write_number;//记录待写入的字符数

	if(fp < _iob || fp >= _iob + OPEN_MAX)//如果指针不是指向结构数组的成员
		return EOF;

	if(fp -> flag._WRITE == 0 || fp -> flag._EOF == 1 || fp -> flag._ERR == 1)
		return EOF;
	
	bufsize = (fp -> flag._UNBUF) ? 1 : BUFSIZ;

	if(fp -> base == NULL)//如果没有分配缓冲区
	{
		if((fp -> base = (char *) malloc(bufsize)) == NULL)
		{
			fp -> flag._ERR = 1;//如果分配缓冲区内存失败，标注错误
			return EOF;
		}
	}
	else
	{
		write_number = fp -> ptr - fp -> base;//待写入字符数为指向当前字符的指针减去指向首字符的指针
		if(write(fp -> fd, fp -> base, write_number) != write_number)//write函数将缓冲区中的数据写入文件中，返回实际写入字符数
		{
			fp -> flag._ERR = 1;//如果实际写入字符数与待写入字符数不相等，说明遇到错误
			return EOF;
		}
	}
	fp -> ptr = fp -> base;//ptr指向缓冲区首字符
	*fp -> ptr++ = (unsigned char)c;
	fp -> cnt = bufsize - 1;
	return c;
}

int fflush(FILE *fp)
{
	int retval = 0;//记录返回值

	if(fp == NULL)//如果fp为NULL，那么就要对结构数组的所有成员进行操作
	{
        int i = 0;
		for(i = 0; i < OPEN_MAX; i++)
			if(_iob[i].flag._WRITE == 1 && (fflush(_iob + i) == -1))//首先判断文件是否是以写的形式打开，如果是执行一次递归，如果返回值为-1
				retval = -1;
	}
	else
	{
		if(fp -> flag._WRITE == 0)//如果文件不是以写的形式打开，直接返回
			return -1;
		_flushbuf(EOF, fp);//冲刷缓冲区，将缓冲区的数据强制写入fp所指向文件中，同时在缓冲区写入EOF
		if(fp -> flag._ERR == 1)//如果出现错误
			retval = -1;
	}
	return retval;
}

int fclose(FILE *fp)
{
	int fd;//保存当前文件描述符
	struct flags news = {0, 0, 0, 0, 0};

	if(fp == NULL)
		return -1;
	fd = fp -> fd;
	fflush(fp);//冲刷缓冲区
	fp -> ptr = NULL;
	if(fp -> base != NULL)
		free(fp -> base);//释放缓冲区分配的空间
	fp -> base = NULL;
	fp -> flag = news;//重置文件模式
	fp -> cnt = 0;
	fp -> fd = -1;//文件描述符标注为-1
	return close(fd);
}
