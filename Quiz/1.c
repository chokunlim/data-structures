#include<stdio.h>

void readData();
void calAverage();
void printData();

void main() {
    double x1, x2, x3, average;
    readData(1, &x1);
    readData(1, &x2);
    readData(1, &x3);
    calAverage(x1, x2, x3, &average);
    printData(x1, x2, x3, average);
}


void readData(int n, double *px){
    printf("Enter value of %d : ", n);
    scanf("%lf", px);
};

void calAverage(double x1, double x2, double x3, double *pAvg){
    *pAvg = (x1+x2+x3) / 3.0;
}

void printData(double x1, double x2, double x3, double avg){
    printf("Average of %.2lf, %.2lf, %.2lf is %.2lf", x1, x2, x3, avg);
    puts("");
}



