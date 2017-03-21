#include "stdio.h"

struct wei_yu   //位域结构体
{
    unsigned short s1: 4;   //low bit
    unsigned short s2: 2;
    unsigned short s3: 2;
    unsigned short s4: 8;   //high bit
};

union sun4i //定义联合体
{
    struct wei_yu s;
    unsigned short data;
};

union endian
{
    int myInt;
    char myByte;
};

//返回1 表示小端模式  返回0 表示大端模式
int check_system(void)
{
    union endian test;
    test.myInt = 1;
    return test.myByte;
}

int main()
{
    union sun4i ss; //定义联合体

    ss.s.s1 = 2; //low bit
    ss.s.s2 = 0;
    ss.s.s3 = 0;
    ss.s.s4 = 1; //high bit

    printf("ss.s1 = 0x%x\r\n",ss.s.s1);
    printf("ss.s2 = 0x%x\r\n",ss.s.s2);
    printf("ss.s3 = 0x%x\r\n",ss.s.s3);
    printf("ss.s4 = 0x%x\r\n",ss.s.s4);
    printf("ss = 0x%x\r\n",ss.data);

    if(check_system())
        printf("this system is little-endian");
    else
        printf("this system is big-endian");

    return 0;
}