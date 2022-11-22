#include <bits/stdc++.h>
using namespace std;

struct edge {
        int u, v, w;
};

int main() {
    int n, m;
    int src;
    cin >> n >> m >> src;
    vector<edge> e(m + 1);
    int dis[n + 1];
    for (int i = 0; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    for (int i = 0; i < m; i++) {
        cin >> e[i].u;
        cin >> e[i].v;
        cin >> e[i].w;
    }
    dis[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = e[j].u;
            int v = e[j].v;
            int w = e[j].w;

            dis[v] = min(dis[v], w + dis[u]);
        }
    }
    for (int i = 1; i < n + 1; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
}