#include <iostream>
using namespace std;

// 2차원 누적 합으로 풀기 O(1) 쿼리 사용
// O(N x M) -> O(N2 + M)

int table[1025][1025];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x1, x2, y1, y2, answer;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> table[i][j];
            table[i][j] += table[i][j-1] + table[i-1][j] - table[i-1][j-1];
        }
    }
    while (m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << table[x2][y2] - table[x1-1][y2] - table[x2][y1-1] + table[x1-1][y1-1] << '\n';
    }
    return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x1, x2, y1, y2, answer;
    cin >> n >> m;
    vector<vector<int>> table(n+1, vector<int>(n+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> table[i][j];
            table[i][j] += table[i][j-1];
        }
    }
    while (m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        answer = 0;
        for (int i=x1; i<=x2; i++) {
            answer += table[i][y2] - table[i][y1-1];
        }
        cout << answer << '\n';
    }

    return 0;
}
*/