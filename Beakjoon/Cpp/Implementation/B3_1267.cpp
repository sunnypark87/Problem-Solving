#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Y=0;
    int M=0;
    int n, time;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>time;
        Y += 10 * ((time / 30) + 1);
        M += 15 * ((time / 60) + 1);
    }

    if (Y == M) cout << "Y M " << M;
    else if (Y > M) cout << "M " << M;
    else cout << "Y " << Y;

    return 0;
}