#include <iostream>
#include <unordered_set>
using namespace std;

int party[50][50];
int p_list[50];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, known, input, flag, answer;
    unordered_set<int> known_list;
    unordered_set<int> black_list;
    cin >> n >> m;
    cin >> known;
    for (int i=0; i<known; i++) {
        cin >> input;
        known_list.insert(input);
    }

    if (!known) {
        cout << m << '\n';
        return 0;
    }

    // 아는 사람이 있는 파티의 모든 사람을 넣는 set을 하나 만들어야 함
    for (int i=0; i<m; i++) {
        cin >> p_list[i];
        flag = 0;
        for (int j=0; j<p_list[i]; j++) {
            cin >> party[i][j];
            if (known_list.find(party[i][j]) != known_list.end()) flag = 1;     
        }
        if (flag) {
            for (int j=0; j<p_list[i]; j++) {
                known_list.insert(party[i][j]);
            }
        }
    }

    answer = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<p_list[i]; j++) {
            if (known_list.find(party[i][j]) != known_list.end()) break;
            if (j == p_list[i]-1) answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}