#include <bits/stdc++.h>
using namespace std;

bool issafe(int **a, int x, int y, int n) {
    for (int row = 0; row < n; row++) {
        if (a[row][y]) {
            return false;
        }
    }
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0) {
        if (a[row][col]) {
            return false;
        }
        row--, col--;
    }
    row = x, col = y;
    while (row >= 0 && col < n) {
        if (a[row][col]) {
            return false;
        }
        row--, col++;
    }
    return true;
}

bool nqueen(int **a, int x, int n) {
    if (x >= n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j]) {
                    cout << "Q";
                } else {
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return false;
    }

    for (int col = 0; col < n; col++) {
        if (issafe(a, x, col, n)) {
            a[x][col] = 1;

            if (nqueen(a, x + 1, n)) {
                return true;
            }
            a[x][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int **a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    nqueen(a, 0, n);
}

/*Lorem Ipsum*/
/*harshwardhan4k*/
