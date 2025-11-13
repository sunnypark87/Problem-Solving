#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    int sum, answer_sum, answer;

    cin >> n >> m;
    vector<vector<int>> min_path(n+1, vector<int>(n+1, n+1));
    
    for (int i=1; i<n+1; i++) {
        min_path[i][i] = 0;
    }

    for (int i=0; i<m; i++){
        cin >> a >> b;
        min_path[a][b] = 1; 
        min_path[b][a] = 1;
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            for (int k=1; k<n+1; k++) {
                min_path[j][k] = min(min_path[j][k], min_path[j][i]+min_path[i][k]);
            }
        }
    }
    
    for (auto col : min_path) {
        for (auto row : col) {
            cout << row << ' ';
        }
        cout << '\n';
    }

    answer_sum = (n+1) * (n+1);
    for (int i=1; i<n+1; i++) {
        sum = 0;
        for (int j=1; j<n+1; j++) {
            sum += min_path[i][j];
        }
        if (sum < answer_sum) {
            answer_sum = sum;
            answer = i;
        }
    }

    cout << answer << '\n';

    return 0;
}

/*
    pair<int, int> cur;
    vector<vector<int>> friends(n+1, vector<int>(n+1, 0));
    vector<vector<int>> visited(n+1, vector<int>(n+1, 0));
    vector<vector<int>> bacon(n+1, vector<int>(n+1, n+1)); 

    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    queue<pair<int, int>> bfs; 

    for (int i=1; i<n+1; i++) {
        pq.push(make_pair(i, 0));
        bacon[i][i] = 0;
        visited[i][i] = 1;
        while(!pq.empty()) {
            cur = pq.top();
            pq.pop();
            visited[i][cur.first] = 1;
            for (int j=0; j<n+1; j++) {
                if (friends[cur.first][j] && visited[i][j] == 0) {
                    if (cur.second+1 < bacon[i][j]) {
                        bacon[i][j] = cur.second + 1;
                        pq.push(make_pair(j, cur.second + 1));
                    }
                }
            }
        }
    }
*/