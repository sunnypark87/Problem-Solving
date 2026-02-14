#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 트리 지름을 구하는 문제는 BFS/DFS를 2번 실행하는 것으로 해결할 수 있음
// 응용 문제 : 트리 중심 구하기, 트리 반지름, 트리에서 가장 먼 두 노드

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> tree(n+1); 
    vector<int> dist(n+1, 0);


    for (int i=0; i<n-1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        tree[p].push_back({c, w});
        tree[c].push_back({p, w});
    }

    queue<pair<int, int>> bfs;
    bfs.push({1, 0});
    int max = 0;
    int max_dist = 0;
    dist[1] = 1;
    while (!bfs.empty()) {
        int cur = bfs.front().first;
        int cur_dist = bfs.front().second;
        bfs.pop();
        for (int i=0; i<tree[cur].size(); i++) {
            if (!dist[tree[cur][i].first]) {
                bfs.push({tree[cur][i].first, cur_dist + tree[cur][i].second});
                dist[tree[cur][i].first] = cur_dist + tree[cur][i].second;
                if (max_dist < cur_dist + tree[cur][i].second) {
                    max = tree[cur][i].first;
                    max_dist = cur_dist + tree[cur][i].second;
                }   
            }
        }
    }
    
    dist.assign(n+1, 0);
    bfs.push({max, 0});
    dist[max] = 1;
    max = 0;
    max_dist = 0;
    while (!bfs.empty()) {
        int cur = bfs.front().first;
        int cur_dist = bfs.front().second;
        bfs.pop();
        for (int i=0; i<tree[cur].size(); i++) {
           if (!dist[tree[cur][i].first]) {
                bfs.push({tree[cur][i].first, cur_dist + tree[cur][i].second});
                dist[tree[cur][i].first] = cur_dist + tree[cur][i].second;
                if (max_dist < cur_dist + tree[cur][i].second) {
                    max = tree[cur][i].first;
                    max_dist = cur_dist + tree[cur][i].second;
                }   
            }
        }
    }

    cout << max_dist << '\n';

    return 0;
}