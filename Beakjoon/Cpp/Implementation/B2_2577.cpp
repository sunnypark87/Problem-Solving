#include <iostream>
using namespace std;

int num[10];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, mul;
    cin >> a >> b >> c;
    mul = a * b * c;

    while (mul / 10 || mul % 10) {
        num[mul % 10] += 1;
        mul = mul / 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << num[i] << "\n";
    }
    

    return 0;
}