#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string input;
    int answer; 

    while (true) {
        getline(cin, input);
        answer = 0;
        if (input.compare("#") == 0) break;
        for (auto c : input) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') answer++;
        }
        cout << answer << '\n';
    }

    return 0;
}