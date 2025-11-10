#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input, answer;
    int cur_fruit, prev_fruit, prev_pos;
    int length, first_length, second_length;
    cin >> n;
    vector<pair<int, int>> tang(n);
    set<int> check;
    
    prev_fruit = 0;
    prev_pos = 0;
    for (int i=0; i<n; i++) {
        cin >> input;
        cur_fruit = input;
        if (cur_fruit != prev_fruit) {
            tang[prev_pos] = make_pair(prev_fruit, i);
            prev_pos = i;
        }
        tang[i] = make_pair(input, n);
        prev_fruit = cur_fruit;
    }
    
    int i=0;
    int next_pos;
    answer = 0;
    length = 0;
    prev_pos = 0;
    while (i < n) {
        check.insert(tang[i].first);
        if (check.size() == 3) {
            if (length > answer) answer = length;
            length = 0;
            check.clear();
            i = prev_pos;
            check.insert(tang[i].first);
        }
        if (check.size() == 2) {
            prev_pos = i;
        }
        next_pos = tang[i].second;
        length += next_pos - i;
        i = next_pos;
    }
    if (length > answer) answer = length;
    
    cout << answer << '\n';

    return 0;
}