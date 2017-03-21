#include <stdio.h>

int main(void)
{
    char buff[50] = {0};
    char year = 17;
    char mon = 3;
    char day = 3;
    char *str1 = "hello world";

    //格式化输出数据到buff
    sprintf(buff,"%02d-%02d-%02d %s\n",year,mon,day,str1);

    printf("%s",buff);
    return 0;
}