#include <iostream>

using namespace std;

const int MAXN = 100;
const int INF = 1000000000;

int dist[MAXN][MAXN];
int n, m;

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printMatrix() {
    cout << "\nShortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Enter number of vertices (max " << MAXN << "): ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    cout << "Enter each edge as: source destination weight (0-indexed)\n";
    for (int e = 0; e < m; e++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            if (w < dist[u][v])
                dist[u][v] = w;
        }
    }

    floydWarshall();
    printMatrix();

    return 0;
}
