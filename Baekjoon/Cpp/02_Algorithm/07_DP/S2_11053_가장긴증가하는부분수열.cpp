#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LIS (Longest Increasing Subsequence) 문제
// N log N 으로 풀 수도 있음 -> Binary Search
// answer 위치 수정 or max_element로 간단하게 찾을 수 있음
// max 함수로 간단하게

// 문제 풀 때 공통 고려 사항
// 답을 구할 때 입력값이 1개인 경우와 같은 엣지케이스 생각할 것
// 답을 계산할 때는 특정한 조건에만 계산하지 말 것 (아래 for 문 내의 if에서 계산하지 말고 밖에서)

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> sequence(n, 0);
    vector<int> sub_seq(n, 1);
    for (int i=0; i<n; i++) {
        cin >> sequence[i];
    }

    sub_seq[0] = 1;
    for (int i=1; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (sequence[i] > sequence[j]) {
                sub_seq[i] = max(sub_seq[i], sub_seq[j]+1);
            }
        }
    }

    cout << *max_element(sub_seq.begin(), sub_seq.end()) << '\n';

    return 0;
}