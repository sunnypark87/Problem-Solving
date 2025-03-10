#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, v, input;
    int nums[201] = { };
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums[input + 100]++;
    }
    cin >> v;
    cout << nums[v + 100];

    return 0;
}