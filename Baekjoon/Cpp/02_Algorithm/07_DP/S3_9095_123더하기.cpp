#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    int test_case;
    int n;
    vector<int> numbers(11, 0);
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 4;

    for (int i=3; i<11; i++) {
        numbers[i] = numbers[i-3] + numbers[i-2] + numbers[i-1];
    }

    cin>>test_case;
    for (int i=0; i<test_case; i++) {
        cin>>n;
        cout<<numbers[n-1]<<'\n';
    }

    return 0;
}