#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// 최적화 방법
// priority queue 말고 일반 queue 사용
// dx dy dz를 사용해 체크

struct Compare {
    bool operator ()(tuple<int, int, int, int> &a, tuple<int, int, int, int> &b) const {
        return get<3>(a) > get<3>(b);
    };
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, h, x, y, z, step;
    int unripen, answer;
    cin >> m >> n >> h;
    vector<vector<vector<int>>> tomatos(h, vector<vector<int>>(n, vector<int>(m, 0)));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, Compare> min_pq;

    unripen = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                cin >> tomatos[i][j][k];
                if (tomatos[i][j][k] == 0) unripen++;
                else if (tomatos[i][j][k] == 1) min_pq.push(make_tuple(i, j, k, 0));
            }
        }
    }

    if (unripen == 0) {
        cout << 0 << '\n';
        return 0;
    }

    while(!min_pq.empty()) {
        z = get<0>(min_pq.top());
        y = get<1>(min_pq.top());
        x = get<2>(min_pq.top());
        step = get<3>(min_pq.top());
        if (z > 0 && (tomatos[z-1][y][x] == 0)) {
            tomatos[z-1][y][x] = step+1;
            min_pq.push(make_tuple(z-1, y, x, step+1));
        }
        if (z < h-1 && (tomatos[z+1][y][x] == 0)) {
            tomatos[z+1][y][x] = step+1;
            min_pq.push(make_tuple(z+1, y, x, step+1));
        }
        if (y > 0 && (tomatos[z][y-1][x] == 0)) {
            tomatos[z][y-1][x] = step+1;
            min_pq.push(make_tuple(z, y-1, x, step+1));
        }
        if (y < n-1 && (tomatos[z][y+1][x] == 0)) {
            tomatos[z][y+1][x] = step+1;
            min_pq.push(make_tuple(z, y+1, x, step+1));
        }
        if (x > 0 && (tomatos[z][y][x-1] == 0)) {
            tomatos[z][y][x-1] = step+1;
            min_pq.push(make_tuple(z, y, x-1, step+1));
        }
        if (x < m-1 && (tomatos[z][y][x+1] == 0)) {
            tomatos[z][y][x+1] = step+1;
            min_pq.push(make_tuple(z, y, x+1, step+1));
        }
        min_pq.pop();
    }

    answer = -1;
    unripen = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                if (tomatos[i][j][k] == 0) unripen = 1;
                else if (tomatos[i][j][k] > answer) answer = tomatos[i][j][k];
            }
        }
    }

    if (unripen) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}