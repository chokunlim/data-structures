#include <iostream>
#include <queue>
using namespace std;

int main() 
{
    int N;
    cin >> N;

    queue<int> data;
    for (int i = 0; i < N; i++) {

        int command;
        cin >> command;

        switch (command) {
        case 1:
            int x;
            cin >> x;
            data.push(x);
            break;
        case 2:
            if (!data.empty()) {
                data.pop();
            }
            break;

        case 3:
            if (!data.empty()) {
                cout << data.front() << endl;
            } else {
                cout << "EMPTY" << endl;
            }
            break;

        case 4:
            cout << data.size() << endl;
            break;

        default:
            break;
        }

    }


    return 0;
}