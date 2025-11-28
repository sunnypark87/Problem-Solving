#include <iostream>
#include <vector>
using namespace std;

int n, m; 
vector<int> sequence(9, 0);
void combination(int prev, int step) {
    if (step == m) {
        for (int i=0; i<m; i++) {
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=prev; i<=n; i++) {
        sequence[step] = i;
        combination(i, step+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    combination(1, 0);
    
    return 0;
}