#include "calculate.h"
/*
 * 计算函数
 * 定义四则运算的操作，其中要注意除法中除数为零的情况
 */
double Calc(double a,double b,char opt)
{
    double result;   //result用于存放计算得出的结果
    if(opt=='+') result = a + b;
    if(opt=='-') result = a - b;
    if(opt=='*') result = a * b;
    if(opt=='/')     //要防止发生除0错误
    {
        if(fabs(b)<0.00001)
        {
            printf("发生除0错误\n");
            exit(-1);
        }
        result = a / b;
    }
    printf("中间过程输出：  %.2lf %c %.2lf = %.2lf\n", a, opt, b, result);
    return result;    //返回得到的结果
}

/*
 * 转换函数
 * 将操作符转换为cmp数组中的对应的顺序
 */
int change(char opt)
{
    int index = 0;
    switch (opt)
    {
        case '+':
            index = 0;
            break;
        case '-':
            index = 1;
            break;
        case '*':
            index = 2;
            break;
        case '/':
            index = 3;
            break;
        case '(':
            index = 4;
            break;
        case ')':
            index = 5;
            break;
        case '#':
            index = 6;
        default:break;
    }
    return index;
}

/*
 * 比较函数
 * 通过定位cmp中每个元素对应的位置得出先后顺序，其中’？‘表示无法比较
 */
int compare(char opt1,char opt2)
{
    if(cmp[change(opt1)][change(opt2)]=='?'){
        printf("输入表达式错误");
        exit(-1);
    }
    return cmp[change(opt1)][change(opt2)];
}

/*
 * 检查函数
 * 检测输入的算术表达式内是否有非法字符
 */
bool check(char *S, int len){
    int i;
    for(i=0;i<len;i++){
        if(S[i]>='0'&&S[i]<='9')continue;
        if(S[i]=='('||S[i]==')'||S[i]=='*'||S[i]=='/'||S[i]=='+'||S[i]=='-'||S[i]=='.')continue;
        return true;
    }
    return false;
}