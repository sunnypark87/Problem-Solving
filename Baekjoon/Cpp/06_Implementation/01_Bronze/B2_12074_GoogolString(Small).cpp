#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, k;
    int len=0;
    string s = "001";
    string rs;

    for (int i=2; i<=17; i++) {
        rs = s;
        reverse(rs.begin(), rs.end());
        for (int j=0; j<rs.size(); j++) {
            if (rs[j] == '0') rs[j] = '1';
            else rs[j] = '0';
        }
        s = s + "0" + rs;
    }

    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> k;
        cout << "Case #" << i << ": " << s[k-1] << '\n';
    }

    return 0;
}