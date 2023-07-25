#include <stdio.h>

int Kadane() {

}

int main()
{
    int n;
    scanf("%d", &n);

    int orchard[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &orchard[i][j]);
        }
    }

    int maxSum = 0; 

    for (int ROW = 0; ROW < n; ROW++) {

        int arr[n], count;

        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }

        for (int COL = ROW; COL < n; COL++) {
            int curSum = 0;
            for (int j = 0; j < n; j++) {
                arr[j] += orchard[j][COL];
                curSum += arr[j];

                if (curSum > maxSum) {
                    maxSum = curSum;
                }

                if (curSum < 0) {
                    curSum = 0;
                }

            }
        }
        
    }

    printf("%d ", maxSum);

    return 0;
}