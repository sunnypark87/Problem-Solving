#include <iostream>
using namespace std;

int main(void) {
    int w, n;
    int mile_to_feet, answer;
    cin >> w >> n;

    mile_to_feet = w * 5280;
    answer = mile_to_feet / n;

    cout << answer << '\n';

    return 0;
}