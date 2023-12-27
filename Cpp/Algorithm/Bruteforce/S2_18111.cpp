#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m, b;
    int time, block;
    int floor, max, min;
    priority_queue<int> ground;
    vector<int> copy_ground;
    int ans_time, ans_floor;

    cin>>n>>m>>b;
    min = 256;
    max = 0;
    for (int i=0; i<n*m; i++) {
        cin>>floor;
        if (max < floor) {
            max = floor;
        }
        if (min > floor) {
            min = floor;
        }
        ground.push(floor);
    }

    for (int i=0; i<n*m; i++) {
        copy_ground.push_back(ground.top());
        ground.pop();
    }

    ans_time = INT_MAX;
    for (int i=min; i<=max; i++) {
        time = 0;
        block = b;
        for (int j=0; j<n*m; j++) {
            if (copy_ground[j] >= i) {
                time += 2*(copy_ground[j] - i);
                block += (copy_ground[j] - i);
            }
            else {
                if (block >= (i - copy_ground[j])) {
                    time += (i - copy_ground[j]);
                    block -= (i - copy_ground[j]);
                }
                else {
                    time = -1;
                    break;
                }
            }
        }
        if (time >= 0 && time <= ans_time) {
            ans_time = time;
            ans_floor = i;
        }
    }

    cout<<ans_time<<" "<<ans_floor;

    return 0;
}