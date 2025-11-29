#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// 백트태킹으로 푸는게 좀 더 좋음!

struct block {
    int x, y;
    int px, py;
    int step, sum;
};

int main(void) {
    int n, m, x, y, px, py, step, sum, answer;
    cin >> n >> m;
    vector<vector<int>> paper(n, vector<int>(m, 0));
    //vector<vector<int>> answer(n, vector<int>(m, 0));
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    queue<block> bfs;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> paper[i][j];
        }
    }

    answer = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            bfs.push({j, i, j, i, 1, paper[i][j]});
            py = j;
            px = i;
            while (!bfs.empty()) {
                y = bfs.front().y;
                x = bfs.front().x;
                py = bfs.front().py;
                px = bfs.front().px;
                step = bfs.front().step;
                sum = bfs.front().sum;
            
                bfs.pop();
                if (step == 2) {
                    for (int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        for (int l=0; l<4; l++) {
                            int nx2 = x + dx[l];
                            int ny2 = y + dy[l];

                            if ((nx2 == nx && ny2 == ny) || nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if (nx2 < 0 || nx2 >= m || ny2 < 0 || ny2 >= n) continue;
                            
                            if ((nx != px || ny != py) && (nx2 != px || ny2 != py)) {
                                bfs.push({nx, ny, x, y, step+2, sum+paper[ny][nx]+paper[ny2][nx2]});
                            }
                        }
                    }
                }
                if (step == 4) {
                    if (sum > answer) {
                        answer = sum;
                    }
                }
                else {
                    for (int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        
                        if (nx != px || ny != py) {
                            bfs.push({nx, ny, x, y, step+1, sum+paper[ny][nx]});
                        }
                    }
                }
            }
        }
    }

    cout << answer << '\n';

    return 0;
}