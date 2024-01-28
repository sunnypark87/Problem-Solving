#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    int n, b;
    int share, remainder;
    vector<int> remainders;

    cin>>n>>b;

    share = n / b;
    remainder = n % b;
    n = share;
    remainders.push_back(remainder);
    if (share != 0) {
        while (true) {
            if (share < b) {
                remainders.push_back(share);
                break;
            }

            share = n / b;
            remainder = n % b;
            n = share;
            remainders.push_back(remainder);
        }
    }

    for (int i=1; i<=remainders.size(); i++) {
        if (remainders[remainders.size() - i] >= 10) {
            cout<<(char)(remainders[remainders.size() - i] + 55);
        }
        else {
            cout<<remainders[remainders.size() - i];
        }
    }

    return 0;
}