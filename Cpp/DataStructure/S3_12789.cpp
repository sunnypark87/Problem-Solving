#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(void) {


    int n, number, answer;
    queue<int> line;
    stack<int> space;
    
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>number;
        line.push(number);
    }

    answer = 1;
    for (int i=1; i<=n; i++) {
        while(true) {
            if (line.empty()) {
                if (space.empty()) {
                    answer = 0;
                    break;
                }
                else if (space.top() == i) {
                    space.pop();
                    break;
                }
                else {
                    answer = 0;
                    break;
                }
            }
            else if (line.front() == i) {
                line.pop();
                break;
            }
            else {
                if (space.empty()) {
                    space.push(line.front());
                    line.pop();
                }
                if (space.top() == i) {
                    space.pop();
                    break;
                }
                else {
                    space.push(line.front());
                    line.pop();
                }
            }
        }
    }

    if (space.empty()) cout<<"Nice";
    else cout<<"Sad";

    return 0;
}