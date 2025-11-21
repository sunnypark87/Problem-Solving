#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input, min_diff, answer; 

    cin >> n;
    while (n) {
        min_diff = 100000;
        for (int i=1; i<=n; i++) {
            cin >> input;
            if (min_diff > abs(2023 - input)) {
                min_diff = abs(2023 - input);
                answer = i;
            }
        }
        cout << answer << '\n';
        cin >> n;
    }

    return 0;
}