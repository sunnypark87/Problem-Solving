#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> t_size(6);
    int t, p;
    int t_num = 0, p_num = 0;

    cin >> n;
    for (int i=0; i<6; i++) {
        cin >> t_size[i];
    }
    cin >> t >> p;
    
    for (auto a : t_size) {
        if ((a % t) == 0) 
            t_num += a / t;
        else 
            t_num += a / t + 1;
    }

    cout << t_num << '\n';
    cout << (n / p) << ' ' << (n % p);    

    return 0;
}