#include <string>

using namespace std;

// 풀이 리뷰 및 개선
/*
- 모음을 붙여 모든 길이의 단어를 생성하고, word 이하인 단어의 개수를 세는 DFS 풀이
  current > word이면 뒤에 문자를 붙여도 word보다 크므로 해당 가지를 제외해도 된다.
  word 자신까지 세므로 그 개수가 1부터 시작하는 사전 순위다.

- 시간/공간복잡도
  L은 사전의 최대 단어 길이(이 문제에서는 5), 모음 수는 5로 고정한다.
  원본: O(5^L)개의 후보 호출마다 word와 current 복사 및 문자열 비교에 최대 O(L)
  -> 시간 : O(L * 5^L) / 보조 공간 : O(L²)
  -> 깊이 O(L)의 스택에 word 복사와 길이가 늘어나는 current 복사가 함께 유지된다.
  개선: word는 const 참조, current는 공유하며 push_back/pop_back으로 복원
  -> 시간 : O(L * 5^L) / 보조 공간 : O(L)
  -> 문자열 비교는 남으므로 시간 복잡도의 상한은 같고, 복사·불필요한 호출 비용을 줄인다.
  제출 시그니처의 string word 값 전달에 따른 입력 복사 O(|word|)는 별도다.

- 알고리즘 효율성 평가
  길이 1~5의 단어는 5 + 25 + 125 + 625 + 3125 = 3905개로 완전 탐색이 적절하다.
  원본은 길이 5에서도 자식을 호출해 길이 6에서 반환한다.
  -> 최악 19531회 호출을 개선 후 빈 루트 포함 3906회로 줄인다.
  공식 설명에 별도 시간·메모리 제한 수치는 없어 구체적인 실행 시간은 단정하지 않는다.

- 다른 알고리즘 / 풀이 방법
  위치별 가중치 [781, 156, 31, 6, 1]로 순위를 직접 계산할 수도 있다.
  -> i번째 문자의 모음 인덱스(A=0, ..., U=4) * 가중치[i] + 1을 합산한다.
  -> 가중치는 그 위치에서 작은 모음 하나가 만드는 접두사와 모든 확장의 개수다.
  일반화한 최대 길이 L에서는 가중치를 O(L)에 계산하고, 입력을 O(|word|)에 순회한다.
  첫 가중치부터 (weight - 1) / 5로 갱신하면 보조 공간 O(1)이다.
  DFS보다 빠르지만 가중치 유도가 필요하며, 현재 후보 수가 작아 사용자의 DFS를 유지한다.

- 오류 발생 가능성 / 핵심 수정
  공식 입력 조건에서 원본의 뚜렷한 정답 오류는 찾지 못했다.
  answer = -1은 빈 문자열을 세는 동작을 상쇄한다.
  -> answer = 0으로 시작하고 비어 있지 않은 단어만 세어 의미를 명확히 한다.
  길이 5인 단어도 먼저 센 뒤 반환해야 마지막 깊이의 단어가 누락되지 않는다.
  공유 문자열은 재귀 호출 후 pop_back으로 복원해야 다음 형제 분기를 올바르게 만든다.

- 코드 구조/간결성
  읽기 전용 word는 const string&, 변경·복원하는 current는 string&로 전달한다.
  사용하지 않는 vector 헤더를 제거하고 모음 목록은 한 번만 초기화한다.
*/

void count_previous(const string& word, string& current, int& answer) {
    if (current > word) return;
    if (!current.empty()) ++answer;
    if (current.size() == 5) return;

    static const string vowels = "AEIOU";
    for (char c : vowels) {
        current.push_back(c);
        count_previous(word, current, answer);
        current.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    string current;
    count_previous(word, current, answer);
    return answer;
}

// 원본 풀이
/*
#include <string>
#include <vector>

using namespace std;

void count_previous(string word, string current, int& answer) {
    if (current.size() >= 6) return;
    if (current.size() >= 1 && current.compare(word) > 0) return;
    string vowel = "AEIOU";
    answer++;
    
    for (char c : vowel) {
        count_previous(word, current + c, answer);    
    }
}

int solution(string word) {
    int answer = -1;
    string current = "";
    count_previous(word, current, answer); 
    return answer;
}
*/
