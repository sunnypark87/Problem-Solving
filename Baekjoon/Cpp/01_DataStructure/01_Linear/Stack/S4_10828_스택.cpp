/*
#include <iostream>
#include <string>
using namespace std;

int dat[10005];
int pos = 0;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input;
    string command;
    cin >> n;
    while (n > 0) {
        cin >> command;
        if (!command.compare("push")) {
            cin >> input;
            dat[pos] = input;
            pos++;
        }
        else if (!command.compare("pop")) {
            if (pos == 0) cout << -1 << '\n';
            else {
                cout << dat[pos-1] << '\n';
                pos--;
            }                
        }
        else if (!command.compare("top")) {
            if (pos == 0) cout << -1 << '\n';
            else cout << dat[pos-1] << '\n';
        }
        else if (!command.compare("size")) {
            cout << pos << '\n';
        }
        else if (!command.compare("empty")) {
            if (pos == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        n--;
    }

    return 0;
}
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input;
    string command;
    stack<int> s;
    cin >> n;
    while (n > 0) {
        cin >> command;
        if (!command.compare("push")) {
            cin >> input;
            s.push(input);
        }
        else if (!command.compare("pop")) {
            if (!s.size()) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if (!command.compare("top")) {
            if (!s.size()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
        else if (!command.compare("size")) {
            cout << s.size() << '\n';
        }
        else if (!command.compare("empty")) {
            if (!s.size()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        n--;
    }

    return 0;
}
