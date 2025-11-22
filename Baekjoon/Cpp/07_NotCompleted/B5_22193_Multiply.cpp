#include <iostream>
#include <string>
using namespace std;

int main(void) {
    long long n, m, int_a, int_b, answer;
    string a, b;
    cin >> n >> m;
    cin >> a >> b;

    temp = "";
    for (int i=0; i<n; i++) {
        temp += a[i];
    }
    int_a = stoi(temp);
    
    temp = "";
    for (int i=0; i<m; i++) {
        temp += b[i];
    }
    int_b = stoi(temp);

    answer = int_a * int_b;

    cout << answer << '\n';

    return 0;
}