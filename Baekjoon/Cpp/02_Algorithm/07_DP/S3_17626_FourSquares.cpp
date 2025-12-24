#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    int n, x;
    cin >> n;
    int sqrt_n = int(floor(sqrt(n)));
    vector<int> squares(n+1, 0);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sqrt_n; j++) {
            if (i-j*j >= 0) {
                if (squares[i]) squares[i] = min(squares[i], squares[i-j*j]+1);
                else squares[i] = squares[i-j*j]+1;
            }
        }
    }

    for (auto num : squares) {
        cout << num << ' ';
    }
    cout << '\n';

    cout << squares[n] << '\n';

    return 0;
}