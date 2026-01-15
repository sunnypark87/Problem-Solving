#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 중복을 제거할 때 배열에서 확인하지 않고 이전 숫자 변수에 저장해서 사용해도 됨

vector<int> check;
vector<int> answer;

void permutation(vector<int> &numbers, int &n, int &m) {
    if (answer.size() == m) {
        for (auto num : answer) cout << num << ' ';
        cout << '\n';
        return;
    }

    for (int i=0; i<n; i++) {
        if (!check[i]) {
            if (i>0 && numbers[i] == numbers[i-1] && !check[i-1]) continue;
            check[i] = 1;
            answer.push_back(numbers[i]);
            permutation(numbers, n, m);
            answer.pop_back();
            check[i] = 0;
        }
    }

}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, input;
    cin >> n >> m;
    vector<int> number(n, 0);
    for (int i=0; i<n; i++) {
        cin >> number[i];
        check.push_back(0);
    }

    sort(number.begin(), number.end());

    permutation(number, n, m);

    return 0;
}