#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    if (a > b) return true;
    else return false;
}

int main(void) {

    string num;
    vector<int> numbers;

    cin>>num;
    for (int i=0; i<num.size(); i++) {
        numbers.push_back(num[i]-48);
    } 

    sort(numbers.begin(), numbers.end(), compare);
    
    for (int i=0; i<numbers.size(); i++) {
        cout<<numbers[i];
    }

    return 0;
}