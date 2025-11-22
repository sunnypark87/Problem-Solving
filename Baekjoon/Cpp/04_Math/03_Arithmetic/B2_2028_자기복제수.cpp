#include <iostream>
using namespace std;

int main(void) {
    int t, input, square, check;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> input;
        square = input * input;
        check = 1;
        while (input > 0) {
            if (square%10 != input%10) {
                check = 0;
            }
            square /= 10;
            input /= 10;
        }
        if (check) {
            cout << "YES\n"; 
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}