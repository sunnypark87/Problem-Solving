#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    int input;
    stack<int> num;
    long long sum=0;
    cin >> k;
    while (k--) {
        cin >> input;
        if (input == 0) num.pop();
        else num.push(input);
    }

    while (!num.empty()) {
        sum += num.top();
        num.pop();
    }

    cout << sum;

    return 0;
}