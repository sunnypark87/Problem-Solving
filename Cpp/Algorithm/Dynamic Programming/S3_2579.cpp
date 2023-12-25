#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int n;
    int score, greater;
    int result;
    vector<int> stairs;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>score;
        if (i == 0) {
            stairs.push_back(score);
        }
        else if (i == 1) {
            stairs.push_back(score);
            stairs.push_back(score+stairs[0]);
        }
        else if (i == 2) {
            stairs.push_back(score+stairs[0]);
            stairs.push_back(score+stairs[1]);
        }
        else {
            if (stairs[2*i - 5] > stairs[2*i - 4]) {
                greater = stairs[2*i - 5];
            }
            else {
                greater = stairs[2*i - 4];
            }
            stairs.push_back(score+greater);
            stairs.push_back(score+stairs[2*i - 3]);
        }
    }

    if (n == 1) {
        cout<<stairs[0];
    }
    else {
        if (stairs[2*n - 3] > stairs[2*n - 2]) {
            cout<<stairs[2*n - 3];
        }
        else {
            cout<<stairs[2*n - 2];
        }
    }

    return 0;
}