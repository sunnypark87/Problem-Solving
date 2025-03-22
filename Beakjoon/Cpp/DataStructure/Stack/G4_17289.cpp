#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num, input;
    stack<pair<int, int>> nge;
    
    cin >> n;
    num = 0;
    vector<int> ans(n, -1);
    while (n--) {
        cin >> input;
        while (!nge.empty() && nge.top().second < input) {
            ans[nge.top().first] = input;
            nge.pop();
        }
        nge.push(make_pair(num, input));
        num++;
    }

    for (int i : ans) {
        cout << i << ' ';
    }

    return 0;
}