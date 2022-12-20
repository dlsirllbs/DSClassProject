//
// 定义两个动态顺序栈，一个为符号栈，一个为操作数栈，同时定义栈的增删改查的功能
//

#ifndef DSCLASSPROJECT_STACK_H
#define DSCLASSPROJECT_STACK_H

#define STACK_SIZE 100    /*栈初始数组的大小*/
#define STACKINCREMENT 10 /*存储空间分配增量*/

//定义符号栈
typedef struct {
    char *bottom;  /*栈不存在时，值为NULL*/
    char *top;     /*栈顶指针*/
    int stacksize; /*当前已分配空间，以元素为单位*/
} OperatorStack;

//定义操作数栈
typedef struct{
    double *bottom;
    double *top;
    int stacksize;
}NumberStack;

//初始化符号栈
bool init_Stack(OperatorStack *S);
//符号栈出栈函数，弹出栈顶元素，并存入e中。
bool pop(OperatorStack *S, char *e);
//符号栈入栈函数，放到栈顶之中
bool push(OperatorStack *S, char e);
//判断符号栈是否为空
bool isEmpty(OperatorStack *S);
//取符号栈的栈顶值
char getTop(OperatorStack *S);
//显示符号栈内所有值
void showStack(OperatorStack *S);

//初始化操作栈
bool init_Stack(NumberStack *S);
//操作数栈出栈函数，弹出栈顶元素
bool pop(NumberStack *S, double *e);
//操作数栈入栈函数，放入栈顶
bool push(NumberStack *S, double *e);
//判断操作数栈是否为空
bool isEmpty(NumberStack *S);
//取操作数栈的栈顶值
double getTop(NumberStack *S);
//显示操作数栈内的所有值
void showStack(NumberStack *S);


#endif // DSCLASSPROJECT_STACK_H