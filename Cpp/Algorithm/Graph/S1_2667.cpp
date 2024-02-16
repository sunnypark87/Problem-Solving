#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void) {

    int size, buildings, count;
    int x, y;
    bool state;
    string one_line;
    vector<vector<int>> map(27, vector<int> (27, 0));
    queue<pair<int, int>> bfs;
    vector<int> answer;

    cin>>size;
    for (int i=1; i<=size; i++) {
        cin>>one_line;
        for (int j=1; j<=size; j++) {
            map[i][j] = one_line[j-1]-48;
        }
    }

    buildings = 0;
    for (int i=1; i<=size; i++) {
        for (int j=1; j<=size; j++) {
            count = 0;
            if (map[i][j] == 1) {
                buildings++;
                bfs.push(make_pair(i, j));
                while(!bfs.empty()) {
                    x = bfs.front().first;
                    y = bfs.front().second;
                    bfs.pop();
                    if (map[x][y] == 1) {
                        map[x][y] = 0;
                        count++;
                        if (map[x+1][y] == 1) {
                            bfs.push(make_pair(x+1, y));
                        }
                        if (map[x-1][y] == 1) {
                            bfs.push(make_pair(x-1, y));
                        }
                        if (map[x][y+1] == 1) {
                            bfs.push(make_pair(x, y+1));
                        }
                        if (map[x][y-1] == 1) {
                            bfs.push(make_pair(x, y-1));
                        }
                    }
                }
                if (count > 0) {
                    answer.push_back(count);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    for (int i=0; i<answer.size(); i++) {
        cout<<answer[i]<<"\n";
    }

    return 0;
}