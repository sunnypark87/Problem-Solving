#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 풀이 리뷰 및 개선
/*
- 정렬한 숫자에서 사용하지 않은 자릿수를 선택하는 백트래킹 풀이.
  같은 숫자의 선택 순서를 고정하고 선행 0을 제외하면 각 정수를 한 번만 검사한다.
  011처럼 선행 0이 있는 표현은 더 짧은 11에서 이미 검사하므로 제외해도 된다.

- 시간/공간복잡도
  N: 입력 길이, V: 만들 수 있는 최댓값, K: 서로 다른 양의 정수 후보 수.
  R: 원본의 전체 재귀 호출 수, S: 개선 후 전체 재귀 호출 수.
  원본: 길이별로 재탐색하고 numbers/check를 값으로 복사하며 stoi로 변환.
  -> 시간 : O(N log N + NR + K sqrt(V)) / 보조 공간 : O(N^2)
  개선: 모든 접두사를 한 번의 탐색에서 검사하고 정수를 누적.
  -> 시간 : O(N log N + NS + K sqrt(V)) / 보조 공간 : O(N)
  각 호출의 N개 위치 순회와 소수 판정의 최악 비용을 포함한 상한이다.
  S <= 1 + sum(P(N,k), k=1..N), R <= N*S; 중복 숫자/0 가지치기로 실제 호출은 줄어든다.
  원본은 깊이 N의 스택마다 길이 N인 입력 사본이 남는다.
  solution의 제출용 값 전달에 따른 입력 복사 O(N)은 보조 공간과 별도이다.

- 알고리즘 효율성 평가
  공식 조건 N <= 7, V <= 9,999,999 -> int와 i*i 연산은 이 범위에서 안전하다.
  중복을 무시한 후보 상한은 13,699개이며 소수 판정은 후보당 최대 3,161개 약수 검사.
  원본도 작은 입력에 적절한 방식이다. 반복 탐색과 문자열 복사는 제거할 수 있다.
  공식 설명에 시간/메모리 제한은 명시되지 않아 실행 시간이나 최적성은 단정하지 않는다.

- 다른 알고리즘 / 풀이 방법
  에라토스테네스의 체로 V까지 소수를 미리 구하면 후보 검사는 O(1).
  -> 시간 : O(V log log V + NS) / 공간 : O(V + N)
  숫자 범위가 작거나 많은 후보를 반복 판정할 때 유리하지만 여기서는 최대 약 천만 칸이 필요하다.
  후보가 적은 입력에서도 전체 범위를 처리하므로 기존 제곱근 약수 검사를 유지한다.

- 오류 발생 가능성 / 핵심 수정
  확인한 문제 조건에서 원본의 뚜렷한 정답 오류는 찾지 못했다.
  !used[i-1] 조건은 같은 숫자를 앞의 미사용 숫자보다 먼저 선택하지 않도록 한다.
  이를 제거하면 중복 집계되고, used[i-1]로 뒤집으면 필요한 반복 숫자를 선택하지 못할 수 있다.
  0과 1은 소수가 아니며, 시작 자릿수 0만 제외하고 중간의 0은 허용한다.

- 코드 구조/간결성
  numbers는 const string&로 전달해 재귀마다 입력 사본을 만들지 않는다.
  value * 10 + digit으로 누적해 check 복사와 stoi를 제거한다.
  선택 직후 소수를 검사하고 계속 탐색해 length별 호출과 종료 분기를 제거한다.
*/

bool is_prime(int x) {
    if (x < 2) return false;

    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void get_num(int& answer, const string& numbers, int value, vector<bool>& used) {
    for (int i = 0; i < static_cast<int>(numbers.size()); ++i) {
        if (used[i]) continue;
        if (i > 0 && numbers[i] == numbers[i - 1] && !used[i - 1]) continue;
        if (value == 0 && numbers[i] == '0') continue;

        int next = value * 10 + (numbers[i] - '0');
        used[i] = true;
        if (is_prime(next)) ++answer;
        get_num(answer, numbers, next, used);
        used[i] = false;
    }
}

int solution(string numbers) {
    sort(numbers.begin(), numbers.end());
    vector<bool> used(numbers.size(), false);
    int answer = 0;
    get_num(answer, numbers, 0, used);
    return answer;
}

/* 원본 풀이
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false; 
    
    for (int i=2; i*i<=x; i++) {
        if (x % i == 0) return false;
    }
    
    return true;
}

void get_num(int& answer, string numbers, string check, vector<bool>& used, int length) {
    if (check.size() == length) {
        if (is_prime(stoi(check))) answer++;
        return;
    }
    
    for (int i=0; i<numbers.size(); i++) {
        if (used[i]) continue;
        
        if (i > 0 && numbers[i] == numbers[i-1] && !used[i-1]) continue;
        if (check.size() == 0 && numbers[i] == '0') continue;
        
        check.push_back(numbers[i]);
        used[i] = true;
        
        get_num(answer, numbers, check, used, length);
        
        check.pop_back();
        used[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    vector<bool> used(numbers.size(), false);
    for (int i=1; i<=numbers.size(); i++) {
        get_num(answer, numbers, "", used, i);
    }
    
    return answer;
}
*/
