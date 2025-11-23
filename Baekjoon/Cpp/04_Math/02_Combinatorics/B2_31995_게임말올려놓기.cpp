#include <iostream>
using namespace std;

int main(void) {
    int n, m, answer;
    cin >> n >> m;

    if (n < 2 || m < 2) answer = 0;
    else {
        answer = 2 * (n-1) * (m-1);
    }

    cout << answer << '\n';

    return 0;
}