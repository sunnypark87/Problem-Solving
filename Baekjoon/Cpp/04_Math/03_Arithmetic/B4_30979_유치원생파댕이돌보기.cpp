#include <iostream>
using namespace std;

int main(void) {
    int t, n, input, sum, answer;
    cin >> t >> n;
    sum = 0;
    for (int i=0; i<n; i++) {
        cin >> input;
        sum += input;
    }
    if (sum >= t) {
        cout << "Padaeng_i Happy\n";
    }
    else {
        cout << "Padaeng_i Cry\n";
    }
}