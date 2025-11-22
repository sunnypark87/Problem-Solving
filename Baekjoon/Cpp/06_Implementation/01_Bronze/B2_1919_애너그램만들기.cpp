#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word1, word2;
    int ans = 0;
    int alphabet1[26] = { };
    int alphabet2[26] = { };

    cin >> word1 >> word2;
    for (char c : word1) {
        alphabet1[c - 'a']++;
    } 
    for (char c : word2) {
        alphabet2[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (max(alphabet1[i], alphabet2[i]) == alphabet1[i]) {
            ans += alphabet1[i] - alphabet2[i];
        }
        else {
            ans += alphabet2[i] - alphabet1[i];
        }
    }

    cout << ans;

    return 0;
}