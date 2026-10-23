
#include <iostream>
using namespace std;

int main() {
    int n, e;
    int u[100], v[100], w[100];
    int parent[100];

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                int temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;

                temp = u[j];
                u[j] = u[j + 1];
                u[j + 1] = temp;

                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0, count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e && count < n - 1; i++) {
        int a = u[i], b = v[i];

        while (parent[a] != a)
            a = parent[a];

        while (parent[b] != b)
            b = parent[b];

        if (a != b) {
            cout << u[i] << " - " << v[i]
                 << " : " << w[i] << endl;

            totalCost += w[i];
            parent[a] = b;
            count++;
        }
    }

    if (count != n - 1) {
        cout << "Graph is disconnected.\n";
    } else {
        cout << "Minimum cost: " << totalCost << endl;
    }

    return 0;
}
