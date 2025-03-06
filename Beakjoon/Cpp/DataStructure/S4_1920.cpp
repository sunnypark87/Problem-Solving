#include <iostream>
#include <set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m;
    long long input_num;
    set<long long> number_set;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>input_num;
        number_set.insert(input_num);
    }
    
    cin>>m;
    for (int i=0; i<m; i++) {
        cin>>input_num;
        if (number_set.find(input_num) != number_set.end()) {
            cout<<"1\n";
        }
        else {
            cout<<"0\n";
        }
    }


    return 0;
}