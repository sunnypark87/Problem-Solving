#include <iostream>
using namespace std;

int main(void) {

    long long int a, b;
    long long int big, small, remainder;
    long long int answer;
    cin>>a>>b;

    if (a > b) {
        big = a;
        small = b;
    }
    else {
        big = b;
        small = a;
    }
    remainder = a;
    while (true) {
        if (big % small == 0) break;
        remainder = big % small;
        big = small;
        small = remainder;
    }

    answer = a*b/remainder;
    cout<<answer;

    return 0;
}