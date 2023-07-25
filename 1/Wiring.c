#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int h[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    
    int wire = 0;
    for (int i = 0; i < n-1; i++) {
    
        for (int j = i+1; j < n; j++){

            int connectable = 1;
            for (int k = i+1; k < j; k++) {
                if (h[k] >= h[i] || h[k] >= h[j]) {
                    connectable = 0;
                    break;
                }
            }

            if (connectable) { 
                wire++; 
            }
            
        }

    }
    
    printf("%d", wire);

    return 0;
}


