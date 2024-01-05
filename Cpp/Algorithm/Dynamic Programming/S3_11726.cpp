#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    int n;
    vector<int> rectangle(1000, 0);

    rectangle[0] = 1;
    rectangle[1] = 2;

    cin>>n;
    if (rectangle[n-1] == 0) {
        for (int i=2; i<n; i++) {
            rectangle[i] = (rectangle[i-1] + rectangle[i-2]) % 10007;
        }
    }

    cout<<rectangle[n-1];

    return 0;
}