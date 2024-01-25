#include <iostream>
#include <deque>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, input;
    pair<int, int> balloon;
    deque<pair<int, int>> balloons;

    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>input;
        balloons.push_back(make_pair(i, input));
    }
    
    balloon = balloons.front();
    balloons.pop_front();
    cout<<balloon.first<<" ";
    while (!balloons.empty()) {
        if (balloon.second < 0) {
            for (int i=1; i<abs(balloon.second); i++) {
                balloons.push_front(balloons.back());
                balloons.pop_back();
            }
            balloon = balloons.back();
            cout<<balloon.first<<" ";
            balloons.pop_back();
        }
        else {
            for (int i=1; i<balloon.second; i++) {
                balloons.push_back(balloons.front());
                balloons.pop_front();
            }
            balloon = balloons.front();
            cout<<balloon.first<<" ";
            balloons.pop_front();
        }
    }

    return 0;
}