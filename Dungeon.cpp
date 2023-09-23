#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;

    cin >> n;

    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cin >> q;

    int m[q];
    for (int i = 0; i < q; i++) {
        cin >> m[i];
    }

    sort(x, x + n);

    for (int i = 0; i < q; i++) {
        int count = upper_bound(x, x + n, m[i]) - x;
        cout << count << endl;
    }

    return 0;
}
