#include <iostream>
using namespace std;

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // last element as pivot
    int i = low - 1;         // boundary of smaller elements

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);   // move smaller to left
        }
    }

    swap(arr[i + 1], arr[high]);    // place pivot correctly
    return i + 1;                    // return pivot index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);    // sort left
        quickSort(arr, pivotIndex + 1, high);   // sort right
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    int n = 7;

    cout << "Before sorting: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "After sorting:  ";
    printArray(arr, n);

    return 0;
}
