#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, s, y, ans;
    int students[12] = { };

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s >> y;
        students[(6*s + y) - 1]++;
    }

    ans = 0;
    for (int i = 0; i < 12; i++) {
        if (students[i] % k) ans += (students[i] / k) + 1;
        else ans += students[i] / k;
    }
    
    cout << ans;

    return 0;
}