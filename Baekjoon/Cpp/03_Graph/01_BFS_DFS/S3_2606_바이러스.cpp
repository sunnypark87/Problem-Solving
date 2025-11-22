#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int computer, n;
    int a, b; 
    int front;
    int result;

    queue<int> current;

    cin>>computer;
    vector<vector<int>> network(computer+1);
    vector<int> visited(computer+1, 0);

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a>>b;
        network[a].push_back(b);
        network[b].push_back(a);
    }

    for (int i=1; i<network.size(); i++) {
        sort(network[i].begin(), network[i].end());
        for (int j=0; j<network[i].size(); j++) {
            cout<<network[i][j]<<" ";
        }
        cout<<"\n";
    }

    current.push(1);
    visited[1] = 1;
    result = 0;
    
    while (!current.empty()) {
        front = current.front();
        for (int i=0; i<network[front].size(); i++) {
            if (visited[network[front][i]] == 0) {
                cout<<"now visit: "<<network[front][i]<<"\n";
                visited[network[front][i]] = 1;
                current.push(network[front][i]);
                result++;
            }
        }
        current.pop();
    }

    cout<<result;    

    return 0;
}