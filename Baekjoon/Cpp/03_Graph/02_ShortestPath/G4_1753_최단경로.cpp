#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

// 다익스트라 알고리즘
// 최소 힙 사용 방법 : greater 사용 -> 전체 노드를 도는 것보다 빠름
// visited 대신 최소 힙을 사용하고 조건을 추가 -> 최소 힙의 메모리 사용량은 edge의 수

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, e, k, cur, cost, next, next_cost;
    cin >> v >> e;
    cin >> k;
    vector<vector<pair<int, int>>> graph(v+1);
    vector<int> dist(v+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;

    for (int i=0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dist[k] = 0;
    min_pq.push({0, k});

    while(!min_pq.empty()) {
        cost = min_pq.top().first;
        cur = min_pq.top().second;
        min_pq.pop();

        if (cost > dist[cur]) continue;

        for (int i=0; i<graph[cur].size(); i++) {
            next = graph[cur][i].first;
            next_cost = graph[cur][i].second;
            if (dist[next] > dist[cur]+next_cost) {
                dist[next] = dist[cur] + next_cost;
                min_pq.push({dist[next], next});
            }
        }
    }

    for (int i=1; i<=v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}