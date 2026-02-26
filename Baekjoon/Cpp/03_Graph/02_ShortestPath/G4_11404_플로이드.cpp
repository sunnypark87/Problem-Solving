#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// 입력값 받는 반복문 횟수 실수 : m번 해야되는데 n^2번 하고 있었음

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<int>> dist(n+1, vector<int>(n+1, INT_MAX/2));
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int i=1; i<=n; i++) dist[i][i] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (dist[i][j] == INT_MAX/2) cout << "0 ";
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}