#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    vector<int> ans(26);

    cin >> word;

    for (char letter : word) {
        ans[letter-97]++;
    }

    for (int n : ans) {
        cout << n << ' ';
    }

    return 0;
}