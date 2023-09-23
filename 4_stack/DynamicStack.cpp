#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    stack<int> stackdata;
    int command, A;

    for (int i = 0; i < n; i++) {
        cin >> command;
        switch (command) {
            
            case 1: //push
                cin >> A;
                stackdata.push(A);
                break;

            case 2: //pop
                if (!stackdata.empty()) {
                    stackdata.pop();
                }
                break;

            case 3: //print top
                if (!stackdata.empty()) {
                    cout << stackdata.top() << endl;
                } else {
                    cout << "EMPTY" << endl;
                }
                break;

            case 4: //print size
                cout << stackdata.size() << endl;
                break;
        }
    }

    return 0;
}






