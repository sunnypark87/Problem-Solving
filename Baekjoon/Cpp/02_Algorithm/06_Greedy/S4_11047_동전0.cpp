#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    
    int n, k;
    int coin;
    int count=0;
    vector<int> coins;

    cin>>n>>k;
    for (int i=0; i<n; i++) {
        cin>>coin;
        coins.push_back(coin);
    }

    while (k != 0) {
        count += k / coins.back();
        k %= coins.back();
        coins.pop_back();
    }

    cout<<count;

    return 0;
}