#include<stdio.h>

int a(int n){
    if (n == 1){
        return 2;
    } else {
        return a(n-1) + 3;
    }
}

int main()
{
    printf("%d", a(5));
    return 0;
}