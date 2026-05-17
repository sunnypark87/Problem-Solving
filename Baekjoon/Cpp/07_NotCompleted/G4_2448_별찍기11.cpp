#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=0; i<3; i++) {
        for (int j=0; j<5; j++) {
            if (i == 0 && j == 2) cout << '*';
            else if (i == 1 && j%2) cout << '*';
            else if (i == 2) cout << '*';
            else cout << ' ';
            
        }
        cout << '\n';
    }

    return 0;
}