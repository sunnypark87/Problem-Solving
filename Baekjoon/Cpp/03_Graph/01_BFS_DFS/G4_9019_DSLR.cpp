#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b, cur, next;
    
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> a >> b;
        vector<pair<int, char>> visited(10000, make_pair(-1, 'A'));
        queue<int> bfs;
        
        bfs.push(a);
        visited[a].first = a;

        while (!bfs.empty()) {
            cur = bfs.front();
            bfs.pop();

            if (cur == b) break;

            next = (cur * 2) % 10000;
            if (visited[next].first == -1) {
                bfs.push(next);
                visited[next].first = cur;
                visited[next].second = 'D';
            }
            if (cur == 0) next = 9999;
            else next = cur - 1;
            if (visited[next].first == -1) {
                bfs.push(next);  
                visited[next].first = cur;
                visited[next].second = 'S';
            }
            next = 10 * (cur % 1000) + (cur / 1000);
            if (visited[next].first == -1) {
                bfs.push(next);
                visited[next].first = cur;
                visited[next].second = 'L';
            }
            next = 1000 * (cur % 10) + (cur / 10);
            if (visited[next].first == -1) {
                bfs.push(next);
                visited[next].first = cur;
                visited[next].second = 'R';
            }
        }
        
        string answer = "";
        while (cur != a) {
            answer += visited[cur].second;
            cur = visited[cur].first;
        }
        reverse(answer.begin(), answer.end());
        cout << answer << '\n';

    }

    return 0;
}