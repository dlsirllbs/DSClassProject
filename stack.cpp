#include<cstdio>
#include<cstdlib>
#include"stack.h"

/*
 * 初始话符号栈，
 * 分配一个STACK_SIZE大小的数组空间，
 * 并且初始化S.top = S.bottom,初始化栈空间的大小为STACK_SIZE
 */
bool init_Stack(OperatorStack *S){
    S->bottom = (char *) malloc(STACK_SIZE*sizeof(char));
    if(!S->bottom) return false;
    S->top = S->bottom;         /* 操作符栈空时栈顶指针与栈底指针相同 */
    S->stacksize = STACK_SIZE;  /* 栈的初始空间大小为STACK_SIZE */
    return true;
}

/*
 * 入栈，
 * 符号栈读取到符号，将其压入栈内，如果当前栈满，将重新开辟一个新空间
 * 这个新空间位置会发生变化，因此需要bottom和top标定栈的空间的位置
 */
bool push(OperatorStack *S, char e){
    if(S->top - S->bottom >= S->stacksize){     /*栈满，追加存储空间*/
        S->bottom = (char *) realloc(S->bottom, sizeof(char)*(STACK_SIZE + STACKINCREMENT));
    }
    if(!S->bottom) return false;    /* 开辟空间失败，入栈失败 */
    S->top = S->bottom + S->stacksize;
    S->stacksize += STACKINCREMENT;
    *S->top = e;    /* 首先讲元素放入到栈顶指针指向的空位置 */
    S->top++;      /* 栈顶指针加1，e成为新栈顶 */
    return true;
}

/*
 * 出栈，
 * 出栈之前先判断栈是否已空、如果栈不为空，
 * 先将top--，再弹出元素
 */
bool pop(OperatorStack *S, char *e){
/*弹出栈顶元素*/
    if(S->top == S->bottom)
        return false;       /* 栈空，返回失败标志*/
    S->top--;
    *e = *S->top;
    return true;
}

/*
 * 判断栈是否为空，
 * 通过栈底是否等于栈顶判断栈是否为空
 */
bool isEmpty(OperatorStack *S){
    if(S->bottom == S->top) return true;
    return false;
}

/*
 * 取得栈顶值，
 * 先判断栈是否为空，若为空返回标记字符’！‘，表示取值失败
 * 若不为空，先将则取top指针位置减一的位置即为栈顶值所处位置
 */
char getTop(OperatorStack *S){
    if(!isEmpty(S))
    {
        char *temp = S->top;
        temp--;
        return *(temp);
    }
    return '!';
}

/*
 * 显示栈内所有元素
 * 先判断栈内元素是否为空，若为空直接结束
 */
void showStack(OperatorStack *S){
    if (isEmpty(S)) return ;
    for (int i = 0; i < S->top - S->bottom; ++i) {
        std::printf("%c ", S->bottom[i]);
    }
    std::printf("  ");
}

//操作数栈的操作与运算符栈的操作基本一致

/*
 * 初始话操作数栈，
 * 分配一个STACK_SIZE大小的数组空间，
 * 并且初始化S.top = S.bottom,初始化栈空间的大小为STACK_SIZE
 */
bool init_Stack(NumberStack *S){
    S->bottom = (double *) malloc(STACK_SIZE*sizeof(double));
    if(!S->bottom) return false;
    S->top = S->bottom;         /*操作符栈空时栈顶指针与栈底指针相同*/
    S->stacksize = STACK_SIZE;  /*栈的初始空间大小为STACK_SIZE*/
    return true;
}

/*
 * 入栈，
 * 操作数栈读取到操作数，将其压入栈内，如果当前栈满，将重新开辟一个新空间
 * 这个新空间位置会发生变化，因此需要bottom和top标定栈的空间的位置
 */
bool push(NumberStack *S, double *e){
    if(S->top - S->bottom >= S->stacksize){     /*栈满，追加存储空间*/
        S->bottom = (double *) realloc(S->bottom, sizeof(double)*(STACK_SIZE + STACKINCREMENT));
    }
    if(!S->bottom) return false;    /* 开辟空间失败，入栈失败 */
    S->top = S->bottom + S->stacksize;
    S->stacksize += STACKINCREMENT;
    S->top = e;    /* 首先讲元素放入到栈顶指针指向的空位置 */
    S->top++;      /* 栈顶指针加1，e成为新栈顶 */
    return true;
}

/*
 * 出栈，
 * 出栈之前先判断栈是否已空、如果栈不为空，
 * 先将top--，再弹出元素
 */
bool pop(NumberStack *S, double *e){
/*弹出栈顶元素*/
    if(S->top == S->bottom)
        return false;       /* 栈空，返回失败标志*/
    S->top--;
    *e = *S->top;
    return true;
}

/*
 * 判断栈是否为空，
 * 通过栈底是否等于栈顶判断栈是否为空
 */
bool isEmpty(NumberStack *S){
    if(S->bottom == S->top) return true;
    return false;
}

/*
 * 取得栈顶值，
 * 先判断栈是否为空，若为空返回标记数字-1，表示取值失败
 * 若不为空，先将则取top指针位置减一的位置即为栈顶值所处位置
 */
double getTop(NumberStack *S){
    if(!isEmpty(S))
    {
        double *temp = S->top;
        temp--;
        return *(temp);
    }
    return -1;
}

/*
 * 显示栈内所有元素
 * 先判断栈内元素是否为空，若为空直接结束
 */
void showStack(NumberStack *S){
    if (isEmpty(S)) return ;
    for (int i = 0; i < S->top - S->bottom; ++i) {
        std::printf("%lf ", S->bottom[i]);
    }
    std::printf("  ");
}