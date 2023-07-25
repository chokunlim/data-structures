#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int num[n]; int m; int M;

    scanf("%d", &num[0]);
    M = m = num[0];

    for (int i = 1; i < n; i++) { 
        scanf("%d", &num[i]); 
        if (m > num[i]) { m = num[i]; }
        if (M < num[i]) { M = num[i]; }
    }
    printf("%d\n%d", m, M);

    return 0;
}
