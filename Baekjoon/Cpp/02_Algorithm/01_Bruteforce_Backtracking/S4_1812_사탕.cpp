#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input, sum, next, answer;
    cin >> n;
    vector<int> num(n, 0);

    sum = 0;
    for (int i=0; i<n; i++) {
        cin >> num[i];
        sum += num[i];
    }

    sum /= 2;

    for (int i=0; i<n; i++) {
        next = (i + 1)%n;
        answer = sum - num[next];
        for (int j=1; j<(n/2); j++) {
            next = (next+2)%n;
            answer -= num[next];
        }
        cout << answer << '\n'; 
    }

    return 0;
}