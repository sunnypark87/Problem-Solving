#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {
    //ios_base::sync_with_stdio(0);
    //cout.tie(0);
    //cin.tie(0);

    int n, m;
    int input_card;

    map<int, int> card_map;
    vector<int> card_count;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>input_card;
        if (card_map.find(input_card) != card_map.end()) {
            card_map[input_card]++;
        }
        else {
            card_map[input_card] = 1;
        }
    }

    cin>>m;
    for (int i=0; i<m; i++) {
        cin>>input_card;
        if (card_map.find(input_card) != card_map.end()) {
            card_count.push_back(card_map[input_card]);
        }
        else {
            card_count.push_back(0);
        }
    }

    for (int i=0; i<m; i++) {
        cout<<card_count[i]<<" ";
    }
   
    return 0;
}