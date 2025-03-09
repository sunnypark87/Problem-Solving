#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans;
    int six_nine = 0;
    int set[10] = { };
    cin >> n;

    while (n > 0) {
        if (n % 10 == 6 || n % 10 == 9) {
            if (six_nine == 0) {
                set[6]++;
                six_nine = 1;
            }
            else {
                set[9]++;
                six_nine = 0;
            }
        }
        else set[n % 10]++;
        n /= 10;
    }

    ans = 0;
    for (int i = 0; i < 10; i++) {
        if (ans < set[i]) ans = set[i];
    }
    cout << ans;
}