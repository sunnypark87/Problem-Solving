#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 0-1 BFS
// 가중치가 2종류인 bfs의 경우에는 deque을 사용
// 우선순위가 높은 것을 front에 낮은 것을 back에 넣어서 처리

int main(void) {
    int n, k, cur;
    vector<int> pos(100001, 100002);
    deque<int> bfs;

    cin >> n >> k;
    pos[n] = 0;
    bfs.push_front(n);
    while(!bfs.empty()) {
        cur = bfs.front();
        bfs.pop_front();
        if (cur<=50000 && pos[cur*2] > pos[cur]) {
            pos[cur*2] = pos[cur];
            bfs.push_front(cur*2);
        }
        if (cur > 0 && pos[cur-1] > pos[cur]+1) {
            pos[cur-1] = pos[cur]+1;
            bfs.push_back(cur-1);
        }
        if (cur < 100000 && pos[cur+1] > pos[cur]+1) {
            pos[cur+1] = pos[cur]+1;
            bfs.push_back(cur+1);
        }
    }
    cout << pos[k] << '\n';

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {

    int n, k, cur;
    vector<int> pos(100001, 100002);
    queue<int> bfs;

    cin >> n >> k;
    pos[n] = 0;
    bfs.push(n);
    while(!bfs.empty()) {
        cur = bfs.front();
        bfs.pop();
        for (int i=cur*2; i<=100000; i*=2) {
            if (i == 0) break;
            if (pos[i] <= pos[cur]) break;
            pos[i] = pos[cur];
            bfs.push(i);
        }
        if (cur > 0 && pos[cur-1] > pos[cur]+1) {
            pos[cur-1] = pos[cur]+1;
            bfs.push(cur-1);
        }
        if (cur < 100000 && pos[cur+1] > pos[cur]+1) {
            pos[cur+1] = pos[cur]+1;
            bfs.push(cur+1);
        }
    }

    cout << pos[k] << '\n';

    return 0;
}
*/