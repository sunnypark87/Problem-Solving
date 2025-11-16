#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
    double k, p, x; 
    double prev, calc, answer;
    cin >> k >> p >> x;
    prev = k * p + x;
    for (int i=1; i<1000000; i++) {
        calc = (k * p)/i + x * i;
        if (calc > prev) {
            answer = prev;
            break;
        }
        prev = calc;
    }

    cout << fixed << setprecision(3) << answer << '\n';

    return 0;
}