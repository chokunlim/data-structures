#include <iostream>
using namespace std;

void towerOfHanoi(int n, char first_rod, char sec_rod, char third_rod, int &count) {
    if (n == 0) {
        return;
    }

    int *ptrCount = &count;
    (*ptrCount)++;

    towerOfHanoi(n - 1, first_rod, third_rod, sec_rod, count);
    cout << "Move Disk " << n << " from Tower " << first_rod << " -> " << sec_rod << endl;
    towerOfHanoi(n - 1, third_rod, sec_rod, first_rod, count);
}

int main() 
{
    int N = 3;
    int count = 0;

    towerOfHanoi(N, '0', '1', '2', count);

    cout << "Total N = " << count << endl;
    return 0;
}
