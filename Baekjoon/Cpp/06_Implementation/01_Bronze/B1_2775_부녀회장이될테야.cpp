#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int sum_prev_people(int k, int n){
    int sum = 0;
    if (k == 0){
        return n;
    }
    for (int i=1; i<=n; i++){
        sum += sum_prev_people(k-1, i);
    }
    return sum;
}

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int k, n;
    cin>>test_case;
    for(int i=0; i<test_case; i++){
        cin>>k;
        cin>>n;
        cout<<sum_prev_people(k, n)<<"\n";
    }

    return 0;
}