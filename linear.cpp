#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;        
        }
    }
    return -1;               
}

int main() {
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    int n = 7;
    int target = 10;

    int result = linearSearch(arr, n, target);

    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found" << endl;

    return 0;
}

