#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, unripe;
    int day, max_day, cur_x, cur_y, cur_day;
    struct Compare {
        bool operator()(const tuple<int, int, int> a, const tuple<int, int, int> b) {
            return get<2>(a) > get<2>(b);
        };
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> min_pq;

    cin >> m >> n;
    vector<vector<int>> tomato(n, vector<int>(m, 0));

    unripe = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 0) unripe++;
            else if (tomato[i][j] == 1) min_pq.push(make_tuple(i, j, 1));
        }
    }
    unripe += min_pq.size();


    if (unripe == 0) {
        cout << 0 << '\n';
        return 0;
    }

    max_day = 0;
    while (!min_pq.empty()) {
        cur_x = get<0>(min_pq.top());
        cur_y = get<1>(min_pq.top());
        cur_day = get<2>(min_pq.top());
        unripe--;
        if (cur_day > max_day) max_day = cur_day;
        if (cur_x-1 >= 0 && tomato[cur_x-1][cur_y] == 0) {
            tomato[cur_x-1][cur_y] = cur_day+1;
            min_pq.push(make_tuple(cur_x-1, cur_y, cur_day+1));
        }
        if (cur_y-1 >= 0 && tomato[cur_x][cur_y-1] == 0) { 
            tomato[cur_x][cur_y-1] = cur_day+1;
            min_pq.push(make_tuple(cur_x, cur_y-1, cur_day+1));
        }
        if (cur_x+1 < n && tomato[cur_x+1][cur_y] == 0) {
            tomato[cur_x+1][cur_y] = cur_day+1;
            min_pq.push(make_tuple(cur_x+1, cur_y, cur_day+1));
        }
        if (cur_y+1 < m && tomato[cur_x][cur_y+1] == 0) {
            tomato[cur_x][cur_y+1] = cur_day+1;
            min_pq.push(make_tuple(cur_x, cur_y+1, cur_day+1));
        }
        min_pq.pop();
    }

    if (unripe > 0) {
        cout << -1 << '\n';
    }
    else {
        cout << max_day-1 << '\n';   
    }

    return 0;
}