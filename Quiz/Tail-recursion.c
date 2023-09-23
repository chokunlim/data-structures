#include<stdio.h>

int aLinear(int n){
    if (n <= 1) {
        return 2;
    } else {
        return aLinear(n-1) + 3;
    }
}

int aTail(int n, int sum) {
    if (n <= 1) {
        return sum;
    } else {
        return aTail(n-1, sum + 3);
    }
}


int main()
{
    printf("Linear: %d \nTail: %d", aLinear(5), aTail(5, 2));
}