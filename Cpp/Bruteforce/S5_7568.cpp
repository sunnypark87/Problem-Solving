#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    int weight;
    int height;
    vector<pair<int, int>> people_list;
    vector<int> rank_list;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>weight>>height;
        people_list.push_back(make_pair(weight, height));
    }

    for (int i=0; i<n; i++) {
        rank_list.push_back(1);
        for (int j=0; j<n; j++) {
            if (i != j) {
                if (people_list[i].first < people_list[j].first && people_list[i].second < people_list[j].second) {
                    rank_list[i]++;
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout<<rank_list[i]<<'\n';
    }

    return 0;
}