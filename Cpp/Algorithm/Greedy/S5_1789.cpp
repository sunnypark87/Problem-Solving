#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    long long int input;
    int index, count;
    int answer;
    vector<long long int> sums;

    cin>>input;
    index = 0;
    count = 1;
    sums.push_back(0);
    while (true) {
        if (sums[index] >= input) {
            break;
        }
        sums.push_back(sums[index]+count);
        count++;
        index++;
    }

    if (sums[index] == input) {
        cout<<index;
    }
    else {
        cout<<index-1;
    }

    return 0;
}