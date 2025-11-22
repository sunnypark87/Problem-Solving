#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int main(void) {

    int n, m;
    tuple<int, int, int> point;
    int x, y, depth;
    string input;
    vector<vector<int>> maze(102, vector<int> (102, 0));
    queue<tuple<int, int, int>> bfs;

    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>input;
        for (int j=1; j<=m; j++) {
            maze[i][j] = input[j-1]-48;
        }
    }

    bfs.push(make_tuple(1, 1, 1));
    while (true) {
        point = bfs.front();
        x = get<0>(point);
        y = get<1>(point);
        depth = get<2>(point);
        if (x == n && y == m) break;
        bfs.pop();
        if (maze[x-1][y] == 1) {
            bfs.push(make_tuple(x-1, y, depth+1));
            maze[x-1][y] = 0;
        }
        if (maze[x+1][y] == 1) {
            bfs.push(make_tuple(x+1, y, depth+1));
            maze[x+1][y] = 0;
        }
        if (maze[x][y-1] == 1) {
            bfs.push(make_tuple(x, y-1, depth+1));
            maze[x][y-1] = 0;
        }
        if (maze[x][y+1] == 1) {
            bfs.push(make_tuple(x, y+1, depth+1));
            maze[x][y+1] = 0;
        }
    }

    cout<<depth;

    return 0;
}