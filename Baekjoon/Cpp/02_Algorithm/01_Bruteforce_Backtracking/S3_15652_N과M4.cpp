#include <iostream>
#include <vector>
using namespace std;

int n, m; 
void combination(vector<int> sequence, int prev, int step) {
    if (step == m) {
        for (auto num : sequence) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=1; i<=n; i++) {
        if (prev <= i) {
            sequence.push_back(i);
            combination(sequence, i, step+1);
            sequence.pop_back();
        }
    }
}

int main(void) {
    cin >> n >> m;

    vector<int> sequence;

    combination(sequence, 0, 0);
    
    return 0;
}