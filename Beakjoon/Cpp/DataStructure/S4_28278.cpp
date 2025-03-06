#include <iostream>
#include <stack>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, command, input;
    stack<int> numbers;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>command;
        if (command == 1) {
            cin>>input;
            numbers.push(input);
        }
        else if (command == 2) {
            if (numbers.empty()) {
                cout<<-1<<'\n';
            }
            else {
                cout<<numbers.top()<<'\n';
                numbers.pop();
            }
        }
        else if (command == 3) {
            cout<<numbers.size()<<'\n';
        }
        else if (command == 4) {
            if (numbers.empty()) {
                cout<<1<<'\n';
            }
            else {
                cout<<0<<'\n';
            }
        }
        else {
            if (numbers.empty()) {
                cout<<-1<<'\n';
            }
            else {
                cout<<numbers.top()<<'\n';
            }
        }
    }

    return 0;
}