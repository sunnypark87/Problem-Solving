#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(void) {

    int width, height, x, y;
    int count_blue, count_white;
    int answer_blue, answer_white;
    string input;
    vector<vector<int>> battleground_blue(102, vector<int> (102, 0));
    vector<vector<int>> battleground_white(102, vector<int> (102, 0));
    queue<pair<int, int>> bfs;

    cin>>width>>height;
    for (int i=1; i<=height; i++) {
        cin>>input;
        for (int j=1; j<=width; j++) {
            if (input[j-1] == 'B') {
                battleground_blue[i][j] = 1;
            }
            else {
                battleground_white[i][j] = 1;
            }
        }
    }
    
    answer_blue = 0;
    for (int i=1; i<=height+1; i++) {
        for (int j=1; j<=width+1; j++) {
            count_blue = 0;
            if (battleground_blue[i][j] == 1) {
                bfs.push(make_pair(i, j));
                while(!bfs.empty()) {
                    x = bfs.front().first;
                    y = bfs.front().second;
                    bfs.pop();
                    if (battleground_blue[x][y] == 1) {
                        battleground_blue[x][y] = 0;
                        count_blue++;
                        if (battleground_blue[x-1][y] == 1) {
                            bfs.push(make_pair(x-1, y));
                        }
                        if (battleground_blue[x+1][y] == 1) {
                            bfs.push(make_pair(x+1, y));
                        }
                        if (battleground_blue[x][y-1] == 1) {
                            bfs.push(make_pair(x, y-1));
                        }
                        if (battleground_blue[x][y+1] == 1) {
                            bfs.push(make_pair(x, y+1));
                        }
                    }
                }
            }
            answer_blue += count_blue * count_blue;
        }
    }

    answer_white = 0;
    for (int i=1; i<=height+1; i++) {
        for (int j=1; j<=width+1; j++) {
            count_white = 0;
            if (battleground_white[i][j] == 1) {
                bfs.push(make_pair(i, j));
                while(!bfs.empty()) {
                    x = bfs.front().first;
                    y = bfs.front().second;
                    bfs.pop();
                    if (battleground_white[x][y] == 1) {
                        battleground_white[x][y] = 0;
                        count_white++;
                        if (battleground_white[x-1][y] == 1) {
                            bfs.push(make_pair(x-1, y));
                        }
                        if (battleground_white[x+1][y] == 1) {
                            bfs.push(make_pair(x+1, y));
                        }
                        if (battleground_white[x][y-1] == 1) {
                            bfs.push(make_pair(x, y-1));
                        }
                        if (battleground_white[x][y+1] == 1) {
                            bfs.push(make_pair(x, y+1));
                        }
                    }
                }
            }
            answer_white += count_white * count_white;
        }
    }

    cout<<answer_white<<" "<<answer_blue<<" ";

    return 0;
}