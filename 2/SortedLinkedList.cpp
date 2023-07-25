#include<iostream>
using namespace std;

int main()
{
    int arr[100000];
    int count = 0;
    while (true) {
        int num;
        cin >> num;
        arr[count] = num;
       
        if (num == -1) break;
        count++;
    }

    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for (int i = 0; i < count; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}