#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m, input, x;
    vector<int> kind;
    deque<int> queuestack;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>input;
        kind.push_back(input);
    }

    for (int i=0; i<n; i++) {
        cin>>input;
        if (kind[i] == 0) {
            queuestack.push_front(input);
        }
    }

    cin>>m;
    for (int i=0; i<m; i++) {
        cin>>x;
        queuestack.push_back(x);
        cout<<queuestack.front()<<" ";
        queuestack.pop_front();
    }

    return 0;
}