#include <iostream>
#include <queue>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, time;
    int sum, result;
    priority_queue<int, vector<int>, greater<int>> times;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>time;
        times.push(time);
    }

    sum = 0;
    result = 0;
    for (int i=0; i<n; i++) {
        sum += times.top();
        result += sum;
        times.pop();
    }

    cout<<result;

    return 0;
}