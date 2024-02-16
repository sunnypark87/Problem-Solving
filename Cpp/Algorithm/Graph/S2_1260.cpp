#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int node, line, start;
    int first, second, next;
    vector<vector<int>> graph(1001, vector<int> (1001, 0));
    vector<int> visited(1001, 0);
    stack<int> dfs;
    queue<int> bfs;

    cin>>node>>line>>start;
    for (int i=0; i<line; i++) {
        cin>>first>>second;
        graph[first][second] = 1;
        graph[second][first] = 1;
    }

    dfs.push(start);
    while(!dfs.empty()) {
        next = dfs.top();
        dfs.pop();
        if (visited[next] == 0) {
            visited[next] = 1;
            cout<<next<<" ";
            for (int i=node; i>0; i--) {
                if (graph[next][i] == 1) {
                    if (visited[i] == 0) {
                        dfs.push(i);
                    }
                }
            }
        }
    }
    cout<<"\n";

    visited.clear();
    visited.resize(1001, 0);

    bfs.push(start);
    while(!bfs.empty()) {
        next = bfs.front();
        bfs.pop();
        if (visited[next] == 0) {
            visited[next] = 1;  
            cout<<next<<" ";
            for (int i=1; i<=node; i++) {
                if (graph[next][i] == 1) {
                    if (visited[i] == 0) {
                        bfs.push(i);
                    }
                }
            }
        }
    }

    return 0;
}