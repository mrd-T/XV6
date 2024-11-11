#include <stdio.h>
constexpr int get(int x)
{
    return x*x;
}
int main()
{

    int y=12;
     int x=get(y);
      x=get(123);
      printf("%d",x);
   return 0;
}