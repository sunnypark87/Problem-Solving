#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이 리뷰 및 개선
/*
- 세 사람의 반복 패턴을 i % 패턴 길이로 조회하며 모든 정답과 비교하는 완전 탐색 풀이.
  최고 점수와 같은 사람을 1번부터 추가하므로 동점자도 오름차순으로 반환한다.

- 시간/공간복잡도
  N은 answers의 길이. 각 문제마다 세 사람을 비교하고 마지막에 세 점수를 확인한다.
  -> 시간 : O(N) / 보조 공간 : O(1), 반환 벡터도 최대 3개로 O(1)
  입력 answers 자체는 O(N). 값 전달 시 호출자의 벡터가 복사되면 추가 O(N)이 든다.
  -> 입력 복사까지 포함한 추가 공간 : O(N) (제출용 시그니처 유지)

- 알고리즘 효율성 평가
  최대 10,000문제에서 정답 비교는 3N번, 최대 30,000번 -> 입력 크기에 적절한 선형 탐색이다.
  각 점수를 정확히 계산하려면 모든 정답을 확인해야 하므로 이 방식의 O(N)은 적절하다.
  반복 패턴을 N개로 확장하거나 동점자를 정렬하지 않아 불필요한 작업도 없다.
  고정 배열로 패턴과 점수를 저장하면 동적 할당을 줄일 수 있지만 복잡도는 같고 효과는 작다.
  공식 설명에 시간·메모리 제한 수치는 없으므로 실제 제한 내 통과 여부는 단정하지 않는다.

- 다른 알고리즘 / 풀이 방법
  사람별로 answers를 순회하는 방식: 패턴들을 묶고 사람 번호를 바깥 반복문에 둔다.
  -> 시간 O(3N) = O(N) / 보조 공간 O(1), 값 전달 복사 공간은 현재와 동일.
  사람이 늘어날 때 비교 로직을 재사용하기 쉽지만, 현재 세 사람에는 기존 코드가 충분히 명확하다.
  순환 인덱스 방식: 사람별 인덱스를 증가시키고 패턴 끝에 도달하면 0으로 되돌린다.
  -> 시간 O(N) / 보조 공간 O(1), 나머지 연산 대신 인덱스 갱신과 경계 분기가 필요하다.
  실제 속도 우위는 측정 없이 단정할 수 없고 상태 관리가 늘어나므로 현재 나머지 방식을 유지한다.
  DP나 백트래킹은 재사용할 부분 문제나 선택 분기가 없어 이 문제에서 이점이 없다.

- 오류 발생 가능성 / 핵심 수정
  공식 문제의 패턴과 최대 10,000문제 조건에서 뚜렷한 오류를 찾지 못했다.
  패턴 길이가 서로 달라도 각 패턴의 size()를 사용하므로 반복 경계를 올바르게 처리한다.
  최고 점수가 0이어도 세 사람을 모두 반환하며, 별도 정렬은 필요 없다.

- 코드 구조/간결성
  현재 구조가 짧고 역할이 분명하므로 실행 코드는 유지한다.
  읽기 전용 패턴에 const를 붙이거나 사용하지 않는 <string>을 제거하는 것은 선택 사항이다.
*/

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> first_answer = { 1, 2, 3, 4, 5 };
    vector<int> second_answer = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> third_answer = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    vector<int> correct = { 0, 0, 0 };

    for (int i=0; i<answers.size(); i++) {
        if (answers[i] == first_answer[i % first_answer.size()]) correct[0]++;
        if (answers[i] == second_answer[i % second_answer.size()]) correct[1]++;
        if (answers[i] == third_answer[i % third_answer.size()]) correct[2]++;
    }

    int max_correct = max(correct[0], max(correct[1], correct[2]));

    for (int i=0; i<3; i++) {
        if (max_correct == correct[i]) answer.push_back(i+1);
    }



    return answer;
}
