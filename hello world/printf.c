#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a = 1.12;
    char* str = "hello world";
    char year = 17;
    char mon = 3;
    char day = 3;

    //打印小数点后4位
    printf("a = %.4f\n",a);

    //打印指定长度字符串
    printf("str = %.3s\n",str);

    //按照指定个数占位符输出数据
    printf("%2d-%2d-%2d\n",year,mon,day);

    //按照指定个数占位符输出数据 不足用0补全
    printf("%02d-%02d-%02d\n",year,mon,day);
    return 0;
}