#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, input;
    int cur_x, cur_y, cur_step;
    tuple<int, int, int> cur;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<int>> path(n, vector<int>(m, n*m));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    struct Compare {
        bool operator()(const tuple<int, int, int> a, const tuple<int, int, int> b) {
            return get<2>(a) > get<2>(b);
        }
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> bfs;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                cur = make_tuple(i, j, 0);       
            }
        }
    }

    bfs.push(cur);
    path[get<0>(cur)][get<1>(cur)] = 0;
    while (!bfs.empty()) {
        cur = bfs.top();
        cur_x = get<0>(cur);
        cur_y = get<1>(cur);
        cur_step = get<2>(cur);
        visited[cur_x][cur_y] = 1;
        if ((cur_x-1 >= 0) && (map[cur_x-1][cur_y] == 1) && (visited[cur_x-1][cur_y] == 0)) {
            if (cur_step+1 < path[cur_x-1][cur_y]) {
                path[cur_x-1][cur_y] = cur_step+1;
                bfs.push(make_tuple(cur_x-1, cur_y, cur_step+1));
            }
        }
        if ((cur_y-1 >= 0) && (map[cur_x][cur_y-1] == 1) && (visited[cur_x][cur_y-1] == 0)) {
            if (cur_step+1 < path[cur_x][cur_y-1]) {
                path[cur_x][cur_y-1] = cur_step+1;
                bfs.push(make_tuple(cur_x, cur_y-1, cur_step+1));
            }
        }
        if ((cur_x+1 < n) && (map[cur_x+1][cur_y] == 1) && (visited[cur_x+1][cur_y] == 0)) {
            if (cur_step+1 < path[cur_x+1][cur_y]) {
                path[cur_x+1][cur_y] = cur_step+1;
                bfs.push(make_tuple(cur_x+1, cur_y, cur_step+1));
            }
        }
        if ((cur_y+1 < m) && (map[cur_x][cur_y+1] == 1) && (visited[cur_x][cur_y+1] == 0)) {
            if (cur_step+1 < path[cur_x][cur_y+1]) {
                path[cur_x][cur_y+1] = cur_step+1;
                bfs.push(make_tuple(cur_x, cur_y+1, cur_step+1));
            }
        }
        bfs.pop();
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (map[i][j] == 0) {
                cout << 0 << ' ';
            }
            else if (path[i][j] == n*m) {
                cout << -1 << ' ';
            }
            else {
                cout << path[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    


    return 0;
}