#include <cstring>
#include "stack.h"
#include "calculate.h"
int main() {
    char str1[STACK_SIZE], str2[STACK_SIZE]; //str1��������ʽ��str2�����������
    int len; //������ʾ���ʽ�ĳ���
    OperatorStack oprtn;  //����һ�������ջ
    NumberStack  num;   //����һ��������ջ
    init_Stack(&oprtn);
    init_Stack(&num);
    push(&oprtn, '#');//�����������ջ��ѹ��һ��'#'����������ʽ���ڱ��ʽ���������һ��λ��Ҳ��Ϊ'#'��
                            //֮�����������ʱ������#��������ȽϺ�������'='��ʹ�����յ��������
    std::printf("�������ʽ���� ��'#'��β\n");
    std::scanf("%s",str1);
    std::printf("����Ķ���ʽΪ:%s ", str1);

    len = strlen(str1);
    if(check(str1 ,len)==0)   //����Ƿ�������˷Ƿ��Ķ���
    {
        printf("�����д��ڶ����ַ�\n");
        exit(-1);
    }
}
