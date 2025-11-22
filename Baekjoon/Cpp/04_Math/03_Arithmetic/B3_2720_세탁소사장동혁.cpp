#include <iostream>
using namespace std;

int main(void) {

    int test_case, change;
    int quarter, dime, nickel, penny;

    cin>>test_case;
    for (int i=0; i<test_case; i++) {
        cin>>change;
        quarter = change / 25;
        change %= 25;
        dime = change / 10;
        change %= 10;
        nickel = change / 5;
        penny = change % 5;
        cout<<quarter<<" "<<dime<<" "<<nickel<<" "<<penny<<"\n";
    }

    return 0;
}