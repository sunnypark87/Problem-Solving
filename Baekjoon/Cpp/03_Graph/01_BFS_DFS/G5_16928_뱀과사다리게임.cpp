#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y, pos, step;
    vector<int> game(101, 10000);
    vector<int> ladder(101, 0);
    vector<int> snake(101, 0);
    queue<pair<int, int>> move;

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        ladder[x] = y;
    }
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        snake[x] = y;
    }

    game[1] = 0;
    move.push(make_pair(1, 0));
    while(!move.empty()) {
        pos = move.front().first;
        step = move.front().second;
        for (int i=1; i<=6; i++) {
            if (pos+i <=100) {

                if (ladder[pos+i]) {
                    if (game[ladder[pos+i]] > step+1) {
                        game[pos+i] = step + 1;
                        game[ladder[pos+i]] = step + 1;
                        move.push(make_pair(ladder[pos+i], step+1));
                    }
                }
                else if (snake[pos+i]) {
                    if (game[snake[pos+i]] > step+1) {
                        game[pos+i] = step + 1;
                        game[snake[pos+i]] = step + 1;
                        move.push(make_pair(snake[pos+i], step+1));
                    }
                }
                else {
                    if (game[pos+i] > step+1) {
                        game[pos+i] = step + 1;
                        move.push(make_pair(pos+i, step+1));
                    }
                }
            }
        }
        move.pop();
    }


    cout << game[100] << '\n';


    return 0;
}