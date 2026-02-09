#include <iostream>
using namespace std;

// BFS로 풀었는데 n이 커지면 시간초과 가능성이 높아짐
// -> DP로 다시 풂
// 3차원 DP로 해결할 수 있음 
// 3차원 DP로 생각해볼 것

int house[18][18];
int dp[18][18][3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, answer;
    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> house[i][j];
        }
    }

    dp[1][2][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=3; j<=n; j++) {
            if (!house[i][j]) {
                dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
                dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
                if (!house[i-1][j] && !house[i][j-1]) {
                    dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
                }
            }
        }
    }

    answer = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    cout << answer << '\n';

    return 0;
}