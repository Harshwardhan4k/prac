#include <bits/stdc++.h>

using namespace std;

struct Item {
        int value, weight;
};

bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<Item> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].value >> v[i].weight;
    }
    sort(v.begin(), v.end(), cmp);

    double finalvalue = 0.0;

    for (int i = 0; i < n; i++) {
        if (v[i].weight <= w) {
            w -= v[i].weight;
            finalvalue += v[i].value;
            cout << v[i].weight << endl;

        } else {
            finalvalue += v[i].value * ((double)w / (double)v[i].weight);
            cout << v[i].value * ((double)w / (double)v[i].weight) << endl;
            break;
        }
    }
    cout << finalvalue << endl;
}