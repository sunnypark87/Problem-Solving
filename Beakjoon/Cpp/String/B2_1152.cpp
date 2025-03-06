#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string input;
    int count=0;

    while (cin>>input) {
        if (cin.eof()) break;
        count++;
    }

    cout<<count;

    return 0;
}