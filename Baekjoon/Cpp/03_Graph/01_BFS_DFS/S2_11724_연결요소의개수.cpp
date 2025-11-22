#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 노드가 1개인 component도 고려해야함

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, u, v;
    int search_u, search_v;
    int answer = 0; 
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    vector<int> node_list(n+1, 0);
    queue<pair<int, int>> bfs;
    for (int i=0; i<m; i++) {
        cin >> u >> v; 
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (graph[i][j] == 1) {
                bfs.push(make_pair(i, j));
                node_list[i] = 1;
                node_list[j] = 1;
                graph[i][j] = 0;
                graph[j][i] = 0;
                answer++;
                while (!bfs.empty()) {
                    search_u = bfs.front().first;
                    search_v = bfs.front().second;
                    for (int k=1; k<search_u; k++) {
                        if (graph[k][search_u] == 1) {
                            bfs.push(make_pair(k, search_u));
                            node_list[k] = 1;
                            graph[k][search_u] = 0;
                            graph[search_u][k] = 0;
                        }
                    }
                    for (int k=search_u; k<=n; k++) {
                        if (graph[search_u][k] == 1) {
                            bfs.push(make_pair(search_u, k));
                            node_list[k] = 1;
                            graph[search_u][k] = 0;
                            graph[k][search_u] = 0;
                        }
                    }
                    for (int k=1; k<search_v; k++) {
                        if (graph[k][search_v] == 1) {
                            bfs.push(make_pair(k, search_v));
                            node_list[k] = 1;
                            graph[k][search_v] = 0;
                            graph[search_v][k] = 0;
                        }
                    }
                    for (int k=search_v; k<=n; k++) {
                        if (graph[search_v][k] == 1) {
                            bfs.push(make_pair(search_v, k));
                            node_list[k] = 1;
                            graph[search_v][k] = 0;
                            graph[k][search_v] = 0;
                        }
                    }
                    bfs.pop();
                }
            }
        }
    }
    answer--;
    for (auto &node : node_list) {
        if (node == 0) answer++;
    }

    cout << answer << '\n';

    return 0;
}