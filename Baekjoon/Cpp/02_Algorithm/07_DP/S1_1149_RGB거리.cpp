#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백트레킹은 시간초과
// 입력 배열을 재활용하기 -> 메모리 절약 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, num1, num2;
    cin >> n;
    vector<vector<int>> house(n, vector<int>(3, 0));
    vector<vector<int>> answer(n+1, vector<int>(3, 0));

    for (int i=0; i<n; i++) {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }

    for (int i=0; i<n; i++) {
        num1 = house[i][0] + answer[i][1];
        num2 = house[i][0] + answer[i][2];
        answer[i+1][0] = min(num1, num2);

        num1 = house[i][1] + answer[i][0];
        num2 = house[i][1] + answer[i][2];
        answer[i+1][1] = min(num1, num2);

        num2 = house[i][2] + answer[i][0];
        num1 = house[i][2] + answer[i][1];
        answer[i+1][2] = min(num1, num2);
    }

    cout << min({answer[n][0], answer[n][1], answer[n][2]}) << '\n';
    
    return 0;
}