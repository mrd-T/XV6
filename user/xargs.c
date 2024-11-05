#include "kernel/param.h"
#include "kernel/types.h"
#include "user/user.h"
// #include <stdio.h>
#define  maxx 16
int main(int argv,char* argc[]) {
    //先获取 标准读入
    char buff[maxx];
    read(0, buff, maxx);
    // int p=0;
    // 直接执行
    char *xrgc[maxx];
    int len=0;
    for(int i=1;i<argv;i++)
    {
        xrgc[len]=argc[i];
        len++;
    }
    char *p=buff;
    for(int i=0;i<maxx;i++)
    {
        
        if(buff[i]=='\n')
        {
            printf("%d\n",i);
            int z=fork();
            if(z==0)
            {
                buff[i]=0;
                xrgc[len]=p;
                len++;
                xrgc[len]=0;
                len++;
                exec(argc[1],xrgc);
                exit(0);
            }
            else{
                 p=buff+i+1;
                 wait(0);
            }

        }
    }
}
