    int *f();
//f是一个函数，它返回一个指向int类型的指针
int (*pf)();
//pf是一个指向函数的指针，该函数返回一个int类型的对象
char **argv;
//argv:pointer to pointer to char
//argv是一个二级指针，它指向指针的地址（argv指向参数字符串数组起始位置的指针）
int (*daytab)[13];
//daytab:pointer to array[13] of int
//daytab是一个指针，它指向int类型数组的指针
int *daytab[13];
//daytab:array[13] of pointer to int
//daytab是一个指针数组，数组中每个元素都是一个指向int类型的指针
void *comp11();
//comp11:function returning poniter to void
//comp11是一个函数，它返回一个指向void类型的指针
void (*comp)();
//comp:pointer to function returning void
//comp是一个指向函数的指针，该函数返回一个void类型的对象
char (*(*x())[])();
/* x:function returning pointer to array[] of
pointer to function returning char
x是一个函数，该函数返回一个指向数组的指针，同时该数组被定义为一个指针数组，
其中的每个元素都是一个指针是一个指向函数的指针，该函数返回一个char类型的对象
x是一个函数，该函数返回一个指向指针数组的指针，
数组指针每个元素都是一个指针是一个指向函数的指针，该函数返回一个char类型的对象
*/
char (*(*y[3])())[5];
/* y:array[3] of pointer to function returning
pointer to array[5] of char
y是一个指针数组，该数组中的每个元素是一个指向函数的指针，该函数返回一个指向char类型数组的指针
*/
