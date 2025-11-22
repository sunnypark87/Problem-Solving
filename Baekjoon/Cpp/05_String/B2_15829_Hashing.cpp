#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    int l;
    char a;
    int atoi;
    int r=31;
    long long sum;
    long long m=1234567891;
    long long hash, hash_sum;
    vector<long long> coefficients;

    for (int i=1; i<=50; i++) {
        sum = 1;
        for (int j=1; j<i; j++) {
            sum *= r;
            if (sum >= m) {
                sum %= m;
            }
        }
        coefficients.push_back(sum);
    }

    cin>>l;
    hash_sum = 0;
    for (int i=0; i<l; i++) {
        cin>>a;
        atoi = a - 96;
        hash = coefficients[i] * atoi;
        hash_sum += hash % m;
    }

    cout<<hash_sum%m;

    return 0;
}