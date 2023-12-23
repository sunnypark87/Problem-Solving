#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string sentence;
    bool check;
    stack<char> parenthesis;

    getline(cin, sentence);
    while (sentence[0] != '.') {
        check = true;
        for (char* a=&sentence[0]; *a != '.'; a++){
            if (*a == '(' || *a == '[') {
                parenthesis.push(*a);
            }
            else if (*a == ')') {
                if (!parenthesis.empty()) {
                    if (parenthesis.top() != '(') {
                        check = false;
                        break;
                    }
                    else {
                        parenthesis.pop();
                    }
                }
                else {
                    check = false;
                    break;
                }
            }
            else if (*a == ']') {
                if (!parenthesis.empty()) {
                    if (parenthesis.top() != '[') {
                        check = false;
                        break;
                    }
                    else {
                        parenthesis.pop();
                    }
                }
                else {
                    check = false;
                    break;
                }
            }
        }

        while (!parenthesis.empty()){
            if (check) {
                check = false;
            }
            parenthesis.pop();
        }

        if (check) {
            cout<<"yes"<<'\n';
        }
        else {
            cout<<"no"<<'\n';
        }

        getline(cin, sentence);
    }

    return 0;
}