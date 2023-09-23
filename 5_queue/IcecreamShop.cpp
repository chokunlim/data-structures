#include <iostream>
#include <queue>
using namespace std;

int main() 
{
    int N, T;
    cin >> N;
    cin >> T;

    priority_queue<int, vector<int>, greater<int>> waitingQueue; 

    for (int i = 0; i < N; i++) {
        int waitingTime;
        cin >> waitingTime;
        waitingQueue.push(waitingTime);
    }

    int total = 0;
    while (!waitingQueue.empty() && T > 0) {
        int currCustomerWaitingTime = waitingQueue.top();
        waitingQueue.pop();

        if (currCustomerWaitingTime <= 0) {
            continue;
        } 

        priority_queue<int, vector<int>, greater<int>> tempQueue;
        while (!waitingQueue.empty()) {
            currCustomerWaitingTime = waitingQueue.top();
            waitingQueue.pop();
            if (currCustomerWaitingTime > 1) {
                tempQueue.push(currCustomerWaitingTime - 1);
            }
        }

        waitingQueue = tempQueue;

        total++; T--;
    }
    

    cout << total << endl;

    return 0;
}
