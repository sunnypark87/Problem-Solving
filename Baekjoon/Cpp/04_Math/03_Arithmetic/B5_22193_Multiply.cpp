#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    int n, m, int_a, int_b, mul, temp, zero;
    string a, b;
    cin >> n >> m;
    vector<int> answer(n+m, 0);
    cin >> a >> b;

    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            int_a = a[i] - '0';
            int_b = b[j] - '0';
            answer[i+j+1] += int_a * int_b;
        }
    }

    for (int i=n+m-1; i>0; i--) {
        temp = answer[i];
        answer[i] = temp % 10;
        answer[i-1] += temp / 10;
    }

    if (a == "0" || b == "0") {
        cout << 0 << '\n';
    }
    else {
        zero = 0;
        for (auto c : answer) {
            if (c != 0) zero = 1;
            if (zero == 1) cout << c;
        }
        cout << '\n';
    }

    return 0;
}