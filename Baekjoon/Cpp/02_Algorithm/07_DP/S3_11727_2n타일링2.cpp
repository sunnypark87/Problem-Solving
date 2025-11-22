#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void) {

    int input_number;
    int answer;
    int combination;
    vector<int> power_of_two(1000, 0);

    cin>>input_number;
    power_of_two[0] = 1;
    power_of_two[1] = 3;

    for (int i=2; i<input_number; i++) {
        power_of_two[i] = (power_of_two[i-1] + 2*power_of_two[i-2]) % 10007;    
    }

    cout<<power_of_two[input_number-1];

    return 0;
}