#include <stdio.h>

int main(void)
{
    char *str_s1 = "data:0-0-0,0:0:0,G1929535,60,1,hello,3*1F";
    char *str_s3 = "0F_INFO:88888888,www.umlgps.com,123.57.217.93,9007,CMMTM,1,3,1,4,120,240,3,1,";
    char *str_s2 = "1234567890";
    char str1[20] = {0};
    int sleep_time = 0;
    char str2[10] = {0};
    char str3[20] = {0};

    //提取指定字符串和10进制数据
    sscanf((char *)str_s1, "data:%*d-%*d-%*d,%*d:%*d:%*d,%[^,],%d,%*d,%[^,],%*d", &str1[0], &sleep_time,
           &str2[0]);

    printf("str1 = %s\n",&str1[0]);
	printf("sleep_time = %d\n",sleep_time);
    printf("str2 = %s\n",&str2[0]);

    sscanf(str_s3,"0F_INFO:%[^,]",&str3[0]);
    printf("str3 = %s\n",&str3[0]);

    //截取指定长度的字符串
    sscanf(str_s2, "%5s",&str2[0]);
    printf("5s = %s\n",&str2[0]);

    return 0;
}