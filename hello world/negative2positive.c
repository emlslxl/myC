#include "stdio.h"
#include <stdlib.h>

/**
 * @desc:  负数 转换成 正数表示
 *
 * @param: negative_num 负数的绝对值
 *
 * @return: 一个正值表示的负数
 */
unsigned char absNegative2positive(unsigned char negative_num)
{
    return ((negative_num^0xff) + 1);
}

int main(int argc, char const *argv[]) {
    char positive_num = 1;
    char negative_num = -1;

    unsigned char a = 0;
    unsigned char tmp = 0;

    printf("positive_num = %d \n", positive_num);
    printf("negative_num = %d \n", negative_num);

    tmp = abs(negative_num);    //取负数绝对值
    printf("tmp = %d \n", tmp);

    printf("absNegative2positive = %d \n", absNegative2positive(tmp));

    return 0;
}