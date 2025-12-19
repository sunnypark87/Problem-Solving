#include <iostream>
using namespace std;

// 분할정복에서 동일한 함수의 호출은 저장해놓고 쓰자!

long long multiply(long long n, long long &a, long long &c) {
    if (n == 1) {
        return a;
    }
    if (n == 2) {
        return (a * a) % c;
    }
    long long result = multiply(n/2, a, c);
    if (n % 2) {
        long long temp = (result * result) % c; 
        return (temp * a) % c;
    }
    else {
        return (result * result) % c;
    }
}

int main(void) {
    long long a, b, c;
    cin >> a >> b >> c;

    a = a % c;

    cout << multiply(b, a, c) << '\n';

    return 0;
}