#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m, n, k;
    int x, y;
    int search_x, search_y, answer;
    stack<pair<int, int>> dfs; 

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> m >> n >> k;
        vector<vector<int>> cabbages(n, vector<int>(m, 0));
        answer = 0;
        for (int j=0; j<k; j++) {
            cin >> x >> y;
            cabbages[y][x] = 1;
        }
        
        for (int row=0; row<n; row++) {
            for (int col=0; col<m; col++) {
                if (cabbages[row][col] == 1) {
                    cabbages[row][col] = 0;
                    dfs.push(make_pair(row, col));
                    while(!dfs.empty()) {
                        search_y = dfs.top().first;
                        search_x = dfs.top().second;
                        dfs.pop();
                        
                        if (search_y > 0 && cabbages[search_y-1][search_x] == 1) {
                            cabbages[search_y-1][search_x] = 0;
                            dfs.push(make_pair(search_y-1, search_x));
                        }
                        if (search_x+1 < m && cabbages[search_y][search_x+1] == 1) {
                            cabbages[search_y][search_x+1] = 0;
                            dfs.push(make_pair(search_y, search_x+1));
                        }
                        if (search_y+1 < n && cabbages[search_y+1][search_x] == 1) {
                            cabbages[search_y+1][search_x] = 0;
                            dfs.push(make_pair(search_y+1, search_x));
                        }
                        if (search_x > 0 && cabbages[search_y][search_x-1] == 1) {
                            cabbages[search_y][search_x-1] = 0;
                            dfs.push(make_pair(search_y, search_x-1));
                        }
                        
                    }
                    answer++;
                }         
            }
        }
        cout << answer << '\n';
    }

    return 0;
}