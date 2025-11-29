#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, p, input, answer;
    cin >> n >> p;
    vector<int> sequence(n, 0);
    for (int i=0; i<n; i++) {
        cin >> input;
        sequence[input-p] = 1;
    }

    for (int i=0; i<n; i++) {
        if (sequence[i] == 0) answer = i+p;
    }

    cout << answer << '\n';

    return 0;
}