#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// set 대신에 visited vector를 사용해보자!!
// 초기값도 permutation 함수에서 시작하기

int n, m, input;
vector<int> numbers;

void permutation(vector<int>& sequence, set<int>& check) {
    if (sequence.size() == m) {
        for (auto num : sequence) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=0; i<n; i++) {
        if (!check.count(numbers[i])) {
            sequence.push_back(numbers[i]);
            check.insert(numbers[i]);
            permutation(sequence, check);
            sequence.pop_back();
            check.erase(numbers[i]);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    vector<int> sequence;
    set<int> check;
    for (int i=0; i<n; i++) {
        cin >> input;
        numbers.push_back(input);
    }
    sort(numbers.begin(), numbers.end());

    for (int i=0; i<n; i++) {
        sequence.push_back(numbers[i]);
        check.insert(numbers[i]);
        permutation(sequence, check);
        sequence.pop_back();
        check.erase(numbers[i]);
    }

    return 0;
}