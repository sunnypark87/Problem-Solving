#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    
    int m, n;
    int isPrime;
    double square_root;
    
    cin>>m>>n;
    for (int i=m; i<=n; i++) {
        square_root = ceil(sqrt(i));
        isPrime = 1;
        for (int j=2; j<=(int)square_root; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if ((isPrime == 1 || i == 2) && i != 1) {
            cout<<i<<'\n';
        }
    }

    return 0;
}