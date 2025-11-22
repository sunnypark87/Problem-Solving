#include <iostream>
#include <map>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, count;
    long long input;
    long long nums[10];
    map<long long, int> num_map;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>input;
        nums[i] = input;
        num_map[input] = 0;
    }

    count = 0;
    for (auto& [key, value] : num_map) {
        value = count;
        count++;
    }

    for (int i=0; i<n; i++) {
        cout<<num_map[nums[i]]<<" ";
    }


    return 0;
}