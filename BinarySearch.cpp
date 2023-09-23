#include <iostream>
using namespace std;

void sorted(int arr[], int len) {

    cout << "Unsorted" << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " "; 
    }
    puts("\n");

    for (int i = 0; i < len - 1; i++) {

        for (int j = 0; j < len - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                cout << arr[j] << " <-SWAP-> " << arr[j+1] << endl; 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                for (int k = 0; k < len; k++) {
                    cout << arr[k] << " "; 
                }
                puts("\n");
            }

        }

    }

}

int binarySearch(int array[], int x, int low, int high, int &count) {
    int *ptrCount = &count;

    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x){
            return mid;
        }

        (*ptrCount)++;

        if (array[mid] > x) {
            return binarySearch(array, x, low, mid - 1, count);
        }

        return binarySearch(array, x, mid + 1, high, count);
    }

  return -1;
}

int main() 
{
    int arr[] = {1, 15, 5, 7, 10, 9, 10, 3, 45, 155, 56, 18, 88, 23, 99, 111, 100};
    int len = sizeof(arr) / sizeof(arr[0]);

    sorted(arr, len);
    int count1 = 0;
    int count2 = 0;
    int NUM1 = binarySearch(arr, 5, 0, len - 1, count1);
    int NUM2 = binarySearch(arr, 90, 0, len - 1, count2);

    if (NUM1 != -1) {
        printf("5 is found at index %d N = %d\n", NUM1, count1);
    } else { 
        cout << "5 is not found" << endl;
    }
    
    if (NUM2 != -1) {
        printf("90 is found at index %d N = %d\n", NUM2, count2);
    } else { 
        cout << "90 is not found" << endl;
    }

    return 0;
}
