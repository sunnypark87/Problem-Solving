#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, input;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> stickers(2, vector<int>(n, 0));
        for (int i=0; i<2; i++) {
            for (int j=0; j<n; j++) {
                cin >> stickers[i][j];
            }
        }
        if (n == 1) {
            cout << max(stickers[0][0], stickers[1][0]) << '\n';
            continue;
        }
        stickers[0][1] += stickers[1][0];
        stickers[1][1] += stickers[0][0];
        for (int i=2; i<n; i++) {
            stickers[0][i] += max({stickers[0][i-2], stickers[1][i-2], stickers[1][i-1]});
            stickers[1][i] += max({stickers[0][i-2], stickers[0][i-1], stickers[1][i-2]});
        }

        cout << max({stickers[0][n-2], stickers[0][n-1], stickers[1][n-2], stickers[1][n-1]}) << '\n';
    }

    return 0;
}