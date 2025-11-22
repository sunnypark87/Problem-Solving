#include <iostream>
using namespace std;

int main(void) {
    int n, r, c, answer;
    int divider, remainder, check, step;
    cin >> n >> r >> c;

    answer = 0;
    divider = 2;
    check = 1;
    step = 1;
    for (int i=0; i<n; i++) {
        remainder = c % divider;
        if (remainder >= check) {
            answer += step;
        }
        divider *= 2;
        check *= 2;
        step *= 4;
    }
    
    divider = 2;
    check = 1;
    step = 2;
    for (int i=0; i<n; i++) {
        remainder = r % divider;
        if (remainder >= check) {
            answer += step;
        }
        divider *= 2;
        check *= 2;
        step *= 4;
    }

    cout << answer << '\n';

    return 0;
}