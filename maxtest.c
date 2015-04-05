#include <stdio.h>

int max(int a,int b) {
    int max;
    max = a>b?a:b;
    return max;
}


int main(int argc, const char *argv[])
{
    int result;
    result = max(2,2);
    printf("%d\n",result);
    return 0;
}
