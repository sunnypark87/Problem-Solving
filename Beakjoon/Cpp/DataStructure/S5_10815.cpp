#include <iostream>
#include <unordered_set>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m, card;
    unordered_set<int> cards;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>card;
        cards.insert(card);
    }

    cin>>m;
    for (int i=0; i<m; i++) {
        cin>>card;
        if (cards.find(card) == cards.end()) {
            cout<<0<<" ";
        }
        else {
            cout<<1<<" ";
        }
    }

    return 0;
}