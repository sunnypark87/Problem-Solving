#include <iostream>
using namespace std;

int arr[2000001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, input, ans;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        arr[input] = 1;
    }

    cin >> x;
    ans = 0;
    for (int i = 1; i <= x; i++) {
        if (arr[i]) {
            if (arr[x - i]) ans++;
        }
    }

    cout << ans/2;

    return 0;
}