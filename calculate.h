
#ifndef DSCLASSPROJECT_CALCULATE_H
#define DSCLASSPROJECT_CALCULATE_H
#include<cstdio>
#include<cmath>
/*
 * 定义一个二维数组，用来表示操作符之间( + - * / ( ）#)的先后关系
 */
const char cmp[7][7] = {
        { '>', '>', '<', '<', '<', '>', '>'},
        { '>', '>', '<', '<', '<', '>', '>'},
        { '>', '>', '>', '>', '<', '>', '>'},
        { '>', '>', '>', '>', '<', '>', '>'},
        { '<', '<', '<', '<', '<', '=', '?'},
        { '>', '>', '>', '>', '?', '>', '>'},
        { '<', '<', '<', '<', '<', '?', '='}
};

 // 计算函数，传入两个数以及一个运算符
double Calc(double a,double b,char opt);

//转换函数，将操作符转换为整数，方便在cmp数组中定位比较
int change(char opt);

//比较函数，通过change函数转换两个字符在二维数组的定位，来得出两个操作符的先后运算关系
int compare(char opt1, char opt2);

//检查函数，检查是否含有非法字符
bool check(char *S, int len);

#endif //DSCLASSPROJECT_CALCULATE_H
