#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string input;
    int word[26] = { };
    int test[26] = { };

    cin >> n;
    for (int i = 0; i < n; i++) {
        fill(word, word + 26, 0);
        fill(test, test + 26, 0);
        cin >> input;
        for (char c : input) {
            word[c - 'a']++;
        }
        cin >> input;
        for (char c : input) {
            test[c - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (word[j] != test[j]) {
                cout << "Impossible\n";
                break;
            }
            if (j == 25) {
                cout << "Possible\n";
            }
        }
    }

    return 0;
}