#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int sum, answer, star_pos;
    int weight[2];
    string input;

    cin >> input;
    weight[0] = 1;
    weight[1] = 3;
    sum = 0;
    for (int i=0; i<13; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            sum += (input[i] - '0') * weight[i%2];
        }
        else star_pos = i;
    }
    if (star_pos%2) answer = 7*(10 - (sum % 10))% 10;
    else answer = 10 - (sum%10);
    if (answer == 10) answer = 0;    

    cout << answer << '\n';

    return 0;
}