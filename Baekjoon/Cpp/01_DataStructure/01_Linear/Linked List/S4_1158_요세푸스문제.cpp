#include <iostream>
#include <list>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    list<int> p;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        p.push_back(i);
    }
    
    auto t = p.begin();
    cout << '<';
    while (!p.empty()) {
        for (int i = 1; i < k; i++) {
            t++;
            if (t == p.end()) t = p.begin();
        }
        cout << *t;
        t = p.erase(t);
        if (t == p.end()) t = p.begin();
        if (!p.empty()) cout << ", ";
    }
    cout << '>';
    
    return 0;
}