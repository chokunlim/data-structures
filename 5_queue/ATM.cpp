#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    cin >> x;

    queue<int> atmLine;
    queue<int> withdraw;

    for (int i = 0; i < n; i ++) {
        int numWithdraw;
        cin >> numWithdraw;

        atmLine.push(i+1);
        withdraw.push(numWithdraw);
    }

    while(!atmLine.empty()) {
        if (withdraw.front() <= x) {
            withdraw.pop();
            cout << atmLine.front() << " ";
            atmLine.pop();
        } else {
            withdraw.push(withdraw.front()-x);
            withdraw.pop();
            atmLine.push(atmLine.front());
            atmLine.pop();
        }
    }


    return 0;
}