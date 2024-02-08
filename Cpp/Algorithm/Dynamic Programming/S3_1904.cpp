#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    int n;
    cin>>n;
    vector<int> tiles(n);

    tiles[0] = 1;
    tiles[1] = 2;

    for (int i=2; i<n; i++) {
        tiles[i] = (tiles[i-1] + tiles[i-2]) % 15746;
    }

    cout<<tiles[n-1];

    return 0;
}