#include <iostream>
using namespace std;

int main()
{
    int N, M, K, U, V, result = 0;
    cin >> N >> M;
    cin >> K;

    for (int i = 0; i < M; i++) {
        cin >> U >> V;
        if (U == K || V == K) { 
            result += 1; 
        }
    }

    cout << result;

    return 0;
}
