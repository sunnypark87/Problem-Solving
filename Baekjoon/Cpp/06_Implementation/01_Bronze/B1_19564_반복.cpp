#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 1;
    char prev = 0;
    string input;

    cin >> input;
    for (auto c : input) {
        if (c <= prev) answer++;
        prev = c; 
    }
    
    cout << answer << '\n';

    return 0;
}