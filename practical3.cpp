#include <iostream>
using namespace std;

long long factorialIterative(int n) {
    if (n < 0) {
        cout << "Negative — undefined" << endl;
        return -1;
    }
    if (n == 0 || n == 1) return 1;

    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;

    return result;
}

long long factorialRecursive(int n) {
    if (n < 0) {
        cout << "Negative — undefined" << endl;
        return -1;
    }
    if (n == 0 || n == 1) return 1;  

    return n * factorialRecursive(n - 1);  
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "\n--- Iterative ---" << endl;
    cout << n << "! = " << factorialIterative(n) << endl;

    cout << "\n--- Recursive ---" << endl;
    cout << n << "! = " << factorialRecursive(n) << endl;

    cout << "\n--- Both for 0 to 10 ---" << endl;
    cout << "n\tIterative\tRecursive" << endl;
    cout << "─────────────────────────────" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << i << "\t"
             << factorialIterative(i) << "\t\t"
             << factorialRecursive(i) << endl;
    }

    return 0;
}
