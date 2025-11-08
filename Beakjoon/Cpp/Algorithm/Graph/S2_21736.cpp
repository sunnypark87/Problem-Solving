#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, answer;
    int cur_x, cur_y;
    char input; 
    cin >> n >> m;
    vector<vector<char>> campus(n, vector<char>(m));
    queue<pair<int, int>> bfs;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> input;
            campus[i][j] = input;
            if (input == 'I') {
                cur_x = j;
                cur_y = i;
                bfs.push(make_pair(cur_x, cur_y));
                campus[cur_y][cur_x] = 'X';
            }
        }
    }

    answer = 0;
    while (!bfs.empty()) {
        if (cur_x-1 >= 0) {
            if (campus[cur_y][cur_x-1] == 'P') {
                answer++;
                bfs.push(make_pair(cur_x-1, cur_y));
            }
            else if (campus[cur_y][cur_x-1] == 'O') {
                bfs.push(make_pair(cur_x-1, cur_y));
            }
            campus[cur_y][cur_x-1] = 'X';
        }
        if (cur_x+1 < m) {
            if (campus[cur_y][cur_x+1] == 'P') {
                answer++;
                bfs.push(make_pair(cur_x+1, cur_y));
            }
            else if (campus[cur_y][cur_x+1] == 'O') {
                bfs.push(make_pair(cur_x+1, cur_y));
            }
            campus[cur_y][cur_x+1] = 'X';
        }
        if (cur_y-1 >= 0) {
            if (campus[cur_y-1][cur_x] == 'P') {
                answer++;
                bfs.push(make_pair(cur_x, cur_y-1));
            }
            else if (campus[cur_y-1][cur_x] == 'O') {
                bfs.push(make_pair(cur_x, cur_y-1));
            }
            campus[cur_y-1][cur_x] = 'X';
        }
        if (cur_y+1 < n) {
            if (campus[cur_y+1][cur_x] == 'P') {
                answer++;
                bfs.push(make_pair(cur_x, cur_y+1));
            }
            else if (campus[cur_y+1][cur_x] == 'O') {
                bfs.push(make_pair(cur_x, cur_y+1));
            }
            campus[cur_y+1][cur_x] = 'X';
        }
        bfs.pop();
        cur_x = bfs.front().first;
        cur_y = bfs.front().second;
    }

    if (answer == 0) cout << "TT\n";
    else cout << answer << '\n';

    return 0;
}