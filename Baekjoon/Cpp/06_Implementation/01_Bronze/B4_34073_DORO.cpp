#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string input;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> input;
        cout << input + "DORO" << ' ';    
    }

    cout << '\n';

    return 0;
}