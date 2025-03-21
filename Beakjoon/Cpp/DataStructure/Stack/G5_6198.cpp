#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, no, input;
    long long ans;
    stack<pair<int, int>> buildings;

    cin >> n; 
    no = 1;
    ans = 0;
    buildings.push(make_pair(0, 1000000001));
    while (n--) {
        cin >> input;
        while (buildings.top().second <= input) {
            ans += no - buildings.top().first - 1;
            cout << "no : " << no << " ans : " << ans << '\n';
            buildings.pop();
        }
        buildings.push(make_pair(no, input));
        no++;
    }
    
    while (buildings.top().first != 0) {
        ans += no - buildings.top().first - 1;
        cout << "no : " << no << " ans : " << ans << '\n';
        buildings.pop();
    }

    cout << ans;

    return 0;
}