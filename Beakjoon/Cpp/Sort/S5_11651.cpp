#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        if (p1.second > p2.second) {
            return true;
        }
        else if (p1.second == p2.second) {
            if (p1.first > p2.first) {
                return true;
            }
        }
        return false;
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int x, y;
    pair<int, int> point;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> coordinate;

    cin>>n;
    for (int i=0; i<n; i++){
        cin>>x>>y;
        coordinate.push(make_pair(x, y));
    }

    for (int i=0; i<n; i++){
        point = coordinate.top();
        cout<<point.first<<' '<<point.second<<'\n';
        coordinate.pop();
    }

    return 0;
}