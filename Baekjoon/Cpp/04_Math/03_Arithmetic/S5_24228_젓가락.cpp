#include <iostream>
using namespace std;

int main(void) {
    long long n, r, answer;

    cin >> n >> r;

    answer = (2 * r) + (n-1);

    cout << answer << '\n';

    return 0;
}