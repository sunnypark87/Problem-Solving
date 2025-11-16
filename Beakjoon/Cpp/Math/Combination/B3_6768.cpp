#include <iostream>
using namespace std;

int main(void) {
    int input, answer;
    cin >> input;

    answer = (input-1) * (input-2) * (input-3);
    answer /= 3;
    answer /= 2;

    cout << answer << '\n';
    
    return 0;
}