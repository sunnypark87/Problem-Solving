#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 상하좌우 네 방향을 검사할 때는 방향 배열 사용하기
// 대신 시간이 더 걸림

int r, c;
char board[20][20];
int alphabet[26];
int answer;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int steps) {
    answer = max(answer, steps);

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

        int next = board[ny][nx] - 'A';
        if (alphabet[next]) continue;

        alphabet[next] = 1;
        dfs(ny, nx, steps+1);
        alphabet[next] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> r >> c;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> board[i][j];
        }
    }

    alphabet[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << answer << '\n';

    return 0;
}