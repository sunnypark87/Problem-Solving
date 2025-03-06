#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {

    int max_length;
    string input;
    vector<string> lines(5);

    max_length = 0;
    for (int i=0; i<5; i++) {
        cin>>input;
        if (input.size() > max_length) {
            max_length = input.size();
        }
        lines[i] = input;
    }

    for (int i=0; i<max_length; i++) {
        for (int j=0; j<5; j++) {
            if (lines[j].size() > i) {
                cout<<lines[j][i];
            }
        }
    }
    return 0;
}