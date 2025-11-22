#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    int n, cur_pos;
    cin >> n;
    vector<vector<int>> path(n, vector<int>(n, 0));
    vector<vector<int>> adjacent(n, vector<int>(n, 0));
    queue<int> bfs;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> path[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        bfs.push(i);
        while (!bfs.empty()) {
            cur_pos = bfs.front();
            for (int j=0; j<n; j++) {
                if (path[cur_pos][j] == 1 && adjacent[i][j] == 0) {
                    adjacent[i][j] = 1;
                    bfs.push(j);
                }
            }
            bfs.pop();
        }
    }

    for (auto col : adjacent) {
        for (auto entry : col) {
            cout << entry << ' ';
        }
        cout << '\n';
    }


    return 0;
}