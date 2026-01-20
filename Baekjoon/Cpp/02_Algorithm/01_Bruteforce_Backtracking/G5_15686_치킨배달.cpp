#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// dist 배열보다는 변수에 값을 저장하는게 좋음
// sum의 최댓값 초기활할 때 주의할 것

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, input;
    int h_count, s_count, sum, answer;
    int x_diff, y_diff;
    vector<pair<int, int>> house;
    vector<pair<int, int>> store;
    cin >> n >> m;
    h_count = 0;
    s_count = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> input;
            if (input == 1) {
                h_count++;
                house.push_back(make_pair(i, j));
            }
            else if (input == 2) {
                s_count++;
                store.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> temp(s_count, 1);
    vector<int> dist;
    for (int i=0; i<m; i++) {
        temp[i] = 0;
    }
    
    do {
        answer = 0;
        for (int i=0; i<h_count; i++) {
            sum = 101;
            for (int j=0; j<s_count; j++) {
                if (temp[j] == 0) {
                    x_diff = house[i].first - store[j].first;
                    y_diff = house[i].second - store[j].second;
                    if (sum > abs(x_diff) + abs(y_diff)) {
                        sum = abs(x_diff) + abs(y_diff);
                    }
                }
            }
            answer += sum; 
        }
        dist.push_back(answer);
    } while (next_permutation(temp.begin(), temp.end()));
    
    cout << *min_element(dist.begin(), dist.end()) << '\n';

    return 0;
}