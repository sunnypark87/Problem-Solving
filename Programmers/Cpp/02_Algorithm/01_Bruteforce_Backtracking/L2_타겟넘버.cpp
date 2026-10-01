#include <string>
#include <vector>

using namespace std;

// 풀이 리뷰 및 개선
/*
- 각 숫자에 + / -를 선택하는 DFS 완전탐색이며, 모든 숫자를 사용한 뒤 합을
  비교하므로 각 부호 조합을 한 번씩 정확히 센다.
- 시간: O(2^N). 깊이별 호출 수의 합 : 1 + 2 + ... + 2^N
  공간: 재귀 스택 O(N). solution의 numbers 값 복사도 O(N) 공간 사용
- 함수 인자를 읽기 전용으로 받을 때,
  크기가 큰 경우 (vector<int>) : const vector<int>&로 받음 
  크기가 작은 경우 (int) : int로 받음
- answer를 참조 대신 리턴값으로 계산 
  -> 코드 구조 단순화
*/

int dfs(const vector<int>& numbers, int target, int index, int sum) {
    if (index == numbers.size()) {
        return target == sum;
    }
    return dfs(numbers, target, index+1, sum+numbers[index])
        + dfs(numbers, target, index+1, sum-numbers[index]);
}

int solution(vector<int> numbers, int target) {
    int answer = dfs(numbers, target, 0, 0);

    return answer;
}


// 내가 작성한 코드
/*
void calculate(vector<int>& numbers, int& target, int& answer, int index, int sum) {
    if (index == numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    calculate(numbers, target, answer, index+1, sum + numbers[index]);
    calculate(numbers, target, answer, index+1, sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    calculate(numbers, target, answer, 0, 0);
    
    return answer;
}
*/