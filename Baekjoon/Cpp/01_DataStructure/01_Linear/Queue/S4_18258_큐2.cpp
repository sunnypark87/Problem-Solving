#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, input;
    string command;
    queue<int> numbers;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>command;
        if (command == "push") {
            cin>>input;
            numbers.push(input);
        }
        else if (command == "pop") {
            if (numbers.empty()) {
                cout<<-1<<'\n';
            }
            else {
                cout<<numbers.front()<<'\n';
                numbers.pop();
            }
        }
        else if (command == "size") {
            cout<<numbers.size()<<'\n';
        }
        else if (command == "empty") {
            if (numbers.empty()) {
                cout<<1<<'\n';
            }
            else {
                cout<<0<<'\n';
            }
        }
        else if (command == "front") {
            if (numbers.empty()) {
                cout<<-1<<'\n';
            }
            else {
                cout<<numbers.front()<<'\n';
            }
        }
        else {
            if (numbers.empty()) {
                cout<<-1<<'\n';
            }
            else {
                cout<<numbers.back()<<'\n';
            }
        }
    }

    return 0;
}