#include <iostream>
using namespace std;

int main(void) {
    int a, b, c;
    int first, second;
    cin >> a >> b >> c;

    first = a + b - c;
    for (int i=b; i>0; i/=10) {
        a *= 10;
    }
    second = a + b - c;

    cout << first << '\n' << second << '\n';

    return 0;
}