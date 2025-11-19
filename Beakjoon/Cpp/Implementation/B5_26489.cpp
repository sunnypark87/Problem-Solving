#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int answer=0;
    string line;
    while (getline(cin, line)) {
        answer++;
    }
    
    cout << answer << '\n';

    return 0;
}