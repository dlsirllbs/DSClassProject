#include <cstring>
#include "stack.h"
#include "calculate.h"
int main() {
    char str1[STACK_SIZE], str2[STACK_SIZE]; //str1用来存表达式，str2用来存操作数
    int len; //用来表示表达式的长度
    OperatorStack oprtn;  //创建一个运算符栈
    NumberStack  num;   //创建一个操作数栈
    init_Stack(&oprtn);
    init_Stack(&num);
    push(&oprtn, '#');//事先在运算符栈中压入一个'#'，在输入表达式后，在表达式数组中最后一个位置也设为'#'，
                            //之后在运算结束时这两个#会相见，比较函数返回'='，使得最终的运算结束
    std::printf("输入多项式计算 以'#'结尾\n");
    std::scanf("%s",str1);
    std::printf("输入的多项式为:%s ", str1);

    len = strlen(str1);
    if(check(str1 ,len)==0)   //检查是否多输入了非法的东西
    {
        printf("输入中存在多余字符\n");
        exit(-1);
    }
}
