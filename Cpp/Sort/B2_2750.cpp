#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

    int n, input;
    vector<int> nums;
    
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>input;
        nums.push_back(input);
    }

    sort(nums.begin(), nums.end());

    for (int i=0; i<n; i++) {
        cout<<nums[i]<<'\n';
    }

    return 0;
}