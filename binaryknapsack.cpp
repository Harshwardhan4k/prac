#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cout << "\nEnter the number of items in knapsack: ";
    cin >> n;
    cout << "\nEnter the maximum weight of the knapsack: ";
    cin >> W;
    cout << endl;
    int p[n], w[n], dp[n + 1][W + 1];

    for (int i = 0; i < n; i++) {
        cin >> p[i];

        cin >> w[i];
    }

    // intialize

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (w[i - 1] <= j) {
                dp[i][j] =
                    max(p[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            } else
                dp[i][j] = dp[i - 1][j];
        }
    }

    vector<int> s;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= W; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Max profit is: ";
    cout << dp[n][W];

    int ans = dp[n][W];
    for (int i = n; i > 0 && ans > 0; i--) {
        if (ans == dp[i - 1][W]) {
            continue;
        } else {
            s.push_back(w[i - 1]);
            ans -= p[i - 1];
            W -= w[i - 1];
        }
    }

    cout << "\nSelected items are: ";
    for (int i = 0; i < s.size(); i++) cout << s[i] << " ";
}