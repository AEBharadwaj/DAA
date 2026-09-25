#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int p[], int n)
{
    int m[100][100];

    // Cost is 0 when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            // Try every possible split
            for (int k = i; k < j; k++)
            {
                int cost = m[i][k]
                         + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[100];

    cout << "Enter dimensions of matrices:\n";
    cout << "For A1 = p0 x p1, A2 = p1 x p2, ...\n";

    for (int i = 0; i <= n; i++)
    {
        cout << "p[" << i << "] = ";
        cin >> p[i];
    }

    int result = matrixChainMultiplication(p, n + 1);

    cout << "\nMinimum number of scalar multiplications = "
         << result << endl;

    return 0;
}