/*
#include <iostream>
#include <string>
#include <list>
using namespace std;

const int MX = 600005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;
int cursor = 0;

void move_left() {
    if (cursor == 0) return;
    cursor = pre[cursor];
}

void move_right() {
    if (nxt[cursor] == -1) return;
    cursor = nxt[cursor];
}

void insert(char letter) {
    dat[unused] = letter;
    pre[unused] = cursor;
    nxt[unused] = nxt[cursor];
    if (nxt[cursor] != -1) pre[nxt[cursor]] = unused;
    nxt[cursor] = unused;

    move_right();
    unused++;
}

void erase() {
    if (cursor == 0) return;
    nxt[pre[cursor]] = nxt[cursor];
    if (nxt[cursor] != -1) pre[nxt[cursor]] = pre[cursor];
    move_left();
}

void traverse() {
    int next = nxt[0];
    while (next != -1) {
        cout << dat[next];
        next = nxt[next];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);

    string first_input;
    char command, input;
    int n;

    cin >> first_input;
    for (char c : first_input) {
        insert(c);
    }

    cin>>n;
    for (int i=0; i<n; i++) {
        cin >> command;
        if (command == 'L') move_left();
        else if (command == 'D') move_right();
        else if (command == 'B') erase();
        else if (command == 'P') {
            cin >> input;
            insert(input);
        }
    }
    
    traverse();

    return 0;
}
*/
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> editor;
    string first_input;
    char command, input;
    int n;
    
    cin >> first_input;
    for (char c : first_input) {
        editor.push_back(c);
    }

    cin >> n;
    auto it = editor.end();
    
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == 'L') {
            if (it != editor.begin()) it--;
        }
        else if (command == 'D') {
            if (it != editor.end()) it++;
        }
        else if (command == 'B') {
            if (it != editor.begin()) {
                it--;
                it = editor.erase(it);
            }
        }
        else if (command == 'P') {
            cin >> input;
            it = editor.insert(it, input);
            it++;
        }
    }

    for (char c : editor) {
        cout << c;
    }

    return 0;
}