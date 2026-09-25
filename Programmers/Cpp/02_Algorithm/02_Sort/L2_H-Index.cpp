#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 개선 후 코드
// 내림차순으로 정렬해 논문 수 기준으로 h-index를 계산
// 불필요한 인덱스가 필요하지 않음

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());

    int h = 0;
    for (int citation : citations) {
        if (citation < h) break;
        h++;
    }
    answer = h;

    return answer;
}

// 개선 전 코드 (작성한 solution 원본)
// h는 n이상이 될 수 없음 (10000까지 확인할 필요 없음)
// c++에서는 &&을 왼쪽부터 검사함 -> i < n 비교가 sorted[i] < h 왼쪽으로 와야 함
// citations는 값으로 전달돼 이미 복사된 값으로 다시 새로 변수를 만들 필요 없음

/*
int solution(vector<int> citations) {
    int answer = 0;
    
    int i = 0;
    int n = citations.size();
    vector<int> sorted = citations;
    
    sort(sorted.begin(), sorted.end());
    
    for (int h=0; h<10000; h++) {
        while (sorted[i] < h && i < n) i++;
        if (n - i >= h) answer = h;
    }
    
    return answer;
}
*/

int main(void) {

    vector<vector<int>> citations = {
        { 3, 0, 6, 1, 5 },
        { 1, 2, 3, 4, 6, 7, 8, 9, 10}
    };

    for (auto citation : citations) {
        cout << solution(citation) << '\n';
    }

    return 0;
}
