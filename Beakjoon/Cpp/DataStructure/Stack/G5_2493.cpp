#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input, num, signal;
    stack<pair<int, int>> towers;

    cin >> n;
    num = 1;
    towers.push(make_pair(0, 100000001));
    while (n--) {
        cin >> input;
        while (towers.top().second < input) {

            towers.pop();
        }
        cout << towers.top().first << ' ';
        towers.push(make_pair(num, input));
        num++;
    }
    return 0;
}