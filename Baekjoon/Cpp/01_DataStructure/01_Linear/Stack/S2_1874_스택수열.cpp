#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input, next; 
    vector<char> ans;
    stack<int> num;
    cin >> n;

    num.push(1);
    next = 2;
    ans.push_back('+');
    for (int i = 0; i < n; i++) {
        cin >> input;
        while (true) {
            if (!num.empty()) {
                if (input < num.top() || input < next) {
                    break;
                }
            }
            num.push(next);
            next++;
            ans.push_back('+');
        }
        if (!num.empty()) {
            if (num.top() != input) break;
            else {
                num.pop();
                ans.push_back('-');
            }
        }
    }

    if (num.empty()) {
        for (char c : ans) {
            cout << c << '\n';
        }
    }
    else {
        cout << "NO";
    }


    return 0;
}