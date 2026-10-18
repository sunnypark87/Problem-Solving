#include <vector>
#include <algorithm>

using namespace std;

// 풀이 리뷰 및 개선
/*
- 현재 피로도로 입장 가능한 미방문 던전을 하나씩 선택하는 순열 백트래킹이다.
  가능한 다음 선택을 모두 비교하므로 탐험 가능한 최대 던전 수를 구한다.

- 시간/공간복잡도
  N은 던전 수. 최악의 호출 수는 sum(P(N, d), d=0..N) = O(N!)이다.
  원본: 호출마다 N개 방문 상태를 복사하고 최대 N개 던전을 순회한다.
  -> 시간 : O(N * N!) / 보조 공간 : O(N^2)
  -> 깊이 O(N)의 호출마다 길이 N인 visited 사본이 동시에 유지된다.
  개선: visited를 참조로 공유하고 선택을 취소하여 다음 분기의 상태를 복원한다.
  -> 시간 : O(N * N!) / 보조 공간 : O(N)
  -> 두 구현 모두 제출용 solution의 값 전달 입력 복사 공간 O(N)은 별도이다.

- 알고리즘 효율성 평가
  공식 제한 N <= 8에서 모든 순서를 탐색해도 최대 109,601개 호출이다.
  완전 탐색이 적절하며, 개선은 점근적 시간 개선이 아닌 복사·중복 순회 제거이다.
  공식 문제에 별도 시간·메모리 제한 수치는 없어 실행 시간의 절대치는 단정하지 않는다.

- 다른 알고리즘 / 풀이 방법
  next_permutation으로 인덱스 순열을 열거하고 순서대로 탐험할 수도 있다.
  시간 O(N * N!), 보조 공간 O(N)이며 입장 불가 분기를 일찍 제외하는 DFS를 유지한다.
  비트마스크 DP는 방문 집합별 도달 가능 여부를 기록한다. 같은 집합의 남은 피로도는
  k - 소모량 합으로 일정하므로 시간 O(N * 2^N), 보조 공간 O(2^N)으로 가능하다.
  N이 커지면 유리하지만 현재 제한에서는 기존 백트래킹이 간단하고 충분하다.

- 오류 발생 가능성 / 핵심 수정
  공식 조건에서 원본의 뚜렷한 정답 오류는 찾지 못했다.
  참조 전달로 바꾸면 방문 표시 해제를 반드시 해야 형제 분기가 영향을 받지 않는다.
  answer = count로 시작하면 다음 던전이 없을 때 자연스럽게 count를 반환한다.
  -> is_finished 확인용 순회와 solution의 불필요한 max(0, ...)를 제거한다.

- 코드 구조/간결성
  읽기 전용 dungeons는 const 참조, 공유·복원할 visited는 일반 참조로 전달한다.
  health와 count는 값으로 전달하므로 재귀 호출 뒤 별도 복원이 필요 없다.
  사용하지 않는 string 헤더와 중간 answer 변수를 제거한다.
  조건 출처: https://school.programmers.co.kr/learn/courses/30/lessons/87946
*/

int explore_dungeons(const vector<vector<int>>& dungeons, vector<int>& visited, int health, int count) {
    int answer = count;

    for (int i = 0; i < static_cast<int>(dungeons.size()); ++i) {
        if (visited[i] || health < dungeons[i][0]) continue;

        visited[i] = true;
        answer = max(answer, explore_dungeons(dungeons, visited, health - dungeons[i][1], count + 1));
        visited[i] = false;
    }
    return answer;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> visited(dungeons.size(), 0);
    return explore_dungeons(dungeons, visited, k, 0);
}

/* 원본 풀이
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int explore_dungeons(const vector<vector<int>>& dungeons, vector<int> visited, int health, int count) {
    bool is_finished = true;
    for (int i=0; i<dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= health) {
            is_finished = false;
            break;
        }
    }
    if (is_finished) return count;
    
    int answer = 0;
    
    for (int i=0; i<dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= health) {
            visited[i] = true;
            answer = max(answer, explore_dungeons(dungeons, visited, health-dungeons[i][1], count+1));
            visited[i] = false;
        }
    }
    return answer;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> visited(dungeons.size(), 0);
    answer = max(0, explore_dungeons(dungeons, visited, k, 0));
    
    return answer;
}
*/
