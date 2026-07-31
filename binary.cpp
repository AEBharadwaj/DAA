#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  

        if (arr[mid] == target)
            return mid;                     

        else if (arr[mid] < target)
            low = mid + 1;                  

        else
            high = mid - 1;                
    }
    return -1;                              
}

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;                          

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;

    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target);

    else
        return binarySearchRecursive(arr, low, mid - 1, target);
}

int main() {
    int arr[] = {1, 2, 3, 6, 8, 10, 15};   // must be sorted
    int n = 7;
    int target = 10;

    
    int result = binarySearch(arr, n, target);
    if (result != -1)
        cout << "Iterative: Found at index " << result << endl;
    else
        cout << "Iterative: Not found" << endl;

    
    int result2 = binarySearchRecursive(arr, 0, n - 1, target);
    if (result2 != -1)
        cout << "Recursive: Found at index " << result2 << endl;
    else
        cout << "Recursive: Not found" << endl;

    return 0;
}
