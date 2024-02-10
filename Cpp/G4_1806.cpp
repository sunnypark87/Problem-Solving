#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, limit, input;
    int min_length = INT_MAX;

    cin>>n>>limit;
    vector<long long int> sum(n+1);
    sum[0] = 0;
    
    for (int i=1; i<=n; i++) {
        cin>>input;
        sum[i] = input + sum[i-1];
        if (sum[i] >= limit) {
            if (min_length == INT_MAX) {
                for (int j=0; j<i; j++) {
                    if (sum[i] - sum[j] < limit) break;
                    min_length = i - j;
                }
            }
            else {
                for (int j=i-min_length; j<i; j++) {
                    if (sum[i] - sum[j] < limit) break;
                    min_length = i - j;
                }
            }
        }
    }

    if (min_length == INT_MAX) {
        cout<<0;
    }
    else {
        cout<<min_length;
    }

    return 0;
}