#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q, command;
    int a, b, c, d;
    long long sum;
    cin >> n >> q;
    vector<long long> sequence(n, 0);
    for (int i=0; i<n; i++) {
        cin >> sequence[i];
    }

    for (int i=0; i<q; i++) {
        cin >> command >> a >> b;
        sum = 0;
        for (int j=a-1; j<b; j++) {
            sum += sequence[j];
        }
        if (command == 1) {
            swap(sequence[a-1], sequence[b-1]);
            cout << sum << '\n';
        }
        else {
            cin >> c >> d;
            for (int j=c-1; j<d; j++) {
                sum -= sequence[j];
            }
            cout << sum << '\n';
        }
    }

    return 0;
}