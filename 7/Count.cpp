#include <iostream>
using namespace std;

int main()
{
    int N, K, count = 0;

    cin >> N;
    int array[N];

    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    cin >> K;

    for (int i = 0; i < N; i++) {
        if (array[i] == K) {
            count++;
        }
    }

    cout << count;

    return 0;
}