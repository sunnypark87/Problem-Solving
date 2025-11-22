#include <iostream>
#include <list>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        list<char> password;
        auto iter = password.begin();
        cin >> input;
        for (char c : input) {
            if (c == '<') {
                if (iter != password.begin()) iter--;
            }
            else if (c == '>') {
                if (iter != password.end()) iter++;
            }
            else if (c == '-') {
                if (iter != password.begin()) {
                    iter--;
                    iter = password.erase(iter);
                }
            }
            else {
                password.insert(iter, c);
            }
        }
        for (auto t = password.begin(); t != password.end(); t++) cout << *t;
        cout << "\n";
    }

    return 0;
}