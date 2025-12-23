#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, w, v;
    int max_value = 0;
    cin >> n >> k;
    vector<vector<int>> bags(k+1, vector<int>(n+1, 0));
    for (int i=1; i<=n; i++) {
        cin >> w >> v;
        for (int j=0; j<=k; j++) {
            if (j+w <= k) {
                bags[j][i] = max(bags[j+w][i-1] + v, bags[j][i-1]);
            }
            else {
                bags[j][i] = bags[j][i-1];
            }
            if (bags[j][i] > max_value) max_value = bags[j][i];
        }
    }

    cout << max_value << '\n';

    return 0;
}