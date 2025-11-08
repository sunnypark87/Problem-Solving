#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, input;
    int max_height=0;
    long long sum;
    int left_h, h, right_h, answer;

    cin >> n >> m;
    vector<int> trees(n, 0);
    for (int i=0; i<n; i++) {
        cin >> input;
        if (input > max_height) max_height = input;
        trees[i] = input;
    }

    left_h = 0;
    right_h = max_height;
    h = max_height / 2;
    answer = 0;
    while (right_h - left_h > 1) {
        sum = 0;
        for (int j=0; j<n; j++) {
            if (trees[j] > h) sum += trees[j] - h;
        }
        if (sum >= m) {
            if (h > answer) answer = h;
            left_h = h;
            h += (right_h - left_h) / 2;
        }
        else {
            right_h = h;
            h -= (right_h - left_h) / 2;
        }
    }

    cout << answer << '\n';

    return 0;
}