#include<iostream>
using namespace std;

int main()
{
    int n, m;

    cin >> n;
    cin >> m;

    int arr[m];
    for (int i = 0; i < m; i++) {
            cin >> arr[i];
    }

    for (int i = 0; i < n-1; i++) {
        int temp[m];
        for (int j = 0; j < m; j++) {
            cin >> temp[j];
        }

        for (int k = 0; k < m; k++) {
            arr[k] = temp[arr[k]-1];
        }
        
        /*
        for (int l = 0; l < m; l++) {
            cout << arr[l] << " " << temp[l] << endl;
        }
        */
    }

        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        
    return 0;
}