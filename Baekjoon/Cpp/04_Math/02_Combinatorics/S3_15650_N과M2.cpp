#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> sequence(n, 0);
    vector<int> temp(n, 1);

    for (int i=0; i<n; i++) {
        sequence[i] = i+1;
    }

    for (int i=0; i<m; i++) {
        temp[i] = 0;
    }

    do {
        for (int i=0; i<n; i++) {
            if (temp[i] == 0) cout << sequence[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(temp.begin(), temp.end()));

    return 0;
}