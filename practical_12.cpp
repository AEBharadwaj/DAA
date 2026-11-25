#include <iostream>

using namespace std;

const int MAXN = 16;
const int INF = 1000000000;

int n;
int cost[MAXN][MAXN];
int dp[1 << MAXN][MAXN];
int parent[1 << MAXN][MAXN];

int main() {
    cout << "Enter number of cities (2 to " << MAXN << "): ";
    cin >> n;

    cout << "Enter the " << n << "x" << n << " distance matrix"
         << " (use " << INF << " for no direct road):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int full = (1 << n) - 1;

    for (int mask = 0; mask <= full; mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = INF;
            parent[mask][i] = -1;
        }
    }

    // Start at city 0 with only city 0 visited
    dp[1][0] = 0;

    for (int mask = 1; mask <= full; mask++) {
        if (!(mask & 1)) continue;  // every state must include city 0

        for (int last = 0; last < n; last++) {
            if (!(mask & (1 << last))) continue;
            if (dp[mask][last] == INF) continue;

            for (int next = 0; next < n; next++) {
                if (mask & (1 << next)) continue;
                if (cost[last][next] == INF) continue;

                int newMask = mask | (1 << next);
                int newCost = dp[mask][last] + cost[last][next];

                if (newCost < dp[newMask][next]) {
                    dp[newMask][next] = newCost;
                    parent[newMask][next] = last;
                }
            }
        }
    }

    // Close the tour by returning to city 0
    int best = INF;
    int lastCity = -1;
    for (int i = 1; i < n; i++) {
        if (dp[full][i] == INF || cost[i][0] == INF) continue;
        int total = dp[full][i] + cost[i][0];
        if (total < best) {
            best = total;
            lastCity = i;
        }
    }

    if (best == INF) {
        cout << "\nNo complete tour exists for this graph.\n";
        return 0;
    }

    // Rebuild the tour by walking the parent links backwards
    int tour[MAXN];
    int mask = full;
    int cur = lastCity;
    for (int k = n - 1; k >= 1; k--) {
        tour[k] = cur;
        int prev = parent[mask][cur];
        mask ^= (1 << cur);
        cur = prev;
    }
    tour[0] = 0;

    cout << "\nMinimum tour cost: " << best << "\n";
    cout << "Tour: ";
    for (int k = 0; k < n; k++) {
        cout << tour[k] << " -> ";
    }
    cout << tour[0] << "\n";

    return 0;
}
