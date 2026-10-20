#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

// 풀이 리뷰 및 개선
/*
- 각 전선을 하나씩 제외하고 BFS로 두 전력망의 크기 차이를 구하는 완전 탐색이다.
  트리는 간선 하나를 제거하면 정확히 두 연결 요소로 나뉘므로 모든 절단 후보를 비교하면 된다.

- 시간/공간복잡도
  N은 송전탑 수, 전선 수는 N-1이다.
  원본: 전선마다 두 BFS를 수행하며 인접 행렬의 각 행 N칸을 확인한다.
  시작점 중복 삽입은 각 BFS에서 최대 한 번이므로 지수적으로 증가하지 않는다.
  -> 시간 : O(N^3) / 보조 공간 : O(N^2)
  개선: 인접 리스트에서 전선 하나를 건너뛰며 한쪽 연결 요소만 BFS로 센다.
  트리의 BFS는 O(N), 절단 후보가 N-1개이다.
  -> 시간 : O(N^2) / 보조 공간 : O(N)
  -> 그래프 저장·방문 배열·큐를 포함한다. 제출용 wires 값 전달 복사 O(N)은 별도이다.

- 알고리즘 효율성 평가
  공식 제한 2 <= N <= 100에서 원본의 O(N^3)은 약 100만 규모의 행렬 검사로,
  성능보다 잘못된 개수 계산을 먼저 고쳐야 한다. 별도 시간·메모리 제한 수치는 명시되지 않았다.
  트리는 간선이 N-1개인 희소 그래프이므로 인접 리스트가 저장 공간과 순회 비용에 유리하다.
  한쪽 크기가 size이면 다른 쪽은 N-size -> 두 번째 BFS와 방문 배열 재초기화가 불필요하다.

- 다른 알고리즘 / 풀이 방법
  트리를 루트에서 한 번 DFS하며 서브트리 크기 s를 구하면 부모 간선 절단의 차이는
  abs(N-2*s)이다. 모든 간선을 한 번씩 평가하여 시간 O(N), 보조 공간 O(N)으로 가능하다.
  반복 BFS보다 점근적으로 유리하지만 현재 제한에서는 BFS도 충분하며 원본 접근을 유지한다.
  인접 행렬을 유지하고 방문 표시만 고치는 방법도 가능하지만 시간 O(N^3), 공간 O(N^2)이다.

- 오류 발생 가능성 / 핵심 수정
  원본은 size_a, size_b를 1로 시작하면서 시작점을 방문 표시하지 않는다.
  크기 2 이상인 연결 요소에서는 이웃이 시작점을 다시 큐에 넣어 크기를 1 더 센다.
  예: N=3, wires={{1,2},{2,3}} -> 실제 크기 1과 2를 1과 3으로 계산해 2 반환(정답 1).
  양쪽이 모두 크기 2 이상이면 오차가 상쇄되어 일부 입력에서는 오류가 드러나지 않는다.
  시작점도 큐에 넣기 전에 방문 표시하고, 새 정점을 넣을 때만 개수를 증가시킨다.
  제외할 간선은 양방향으로 건너뛴다. 실제 그래프를 수정하지 않아 복원 누락도 방지한다.

- 코드 구조/간결성
  BFS를 count_component로 분리하고 읽기 전용 그래프를 const 참조로 전달한다.
  차이는 abs(N-2*size)로 계산하고, answer는 입력에 근거한 상한 N으로 초기화한다.
  조건 출처: https://school.programmers.co.kr/learn/courses/30/lessons/86971
*/

int count_component(const vector<vector<int>>& network, int start, int blocked_from, int blocked_to) {
    vector<bool> visited(network.size(), false);
    queue<int> bfs;
    visited[start] = true;
    bfs.push(start);
    int count = 1;

    while (!bfs.empty()) {
        int current = bfs.front();
        bfs.pop();

        for (int next : network[current]) {
            if ((current == blocked_from && next == blocked_to) ||
                (current == blocked_to && next == blocked_from)) continue;
            if (visited[next]) continue;

            visited[next] = true;
            bfs.push(next);
            ++count;
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> network(n + 1);
    for (const auto& wire : wires) {
        network[wire[0]].push_back(wire[1]);
        network[wire[1]].push_back(wire[0]);
    }

    int answer = n;
    for (const auto& wire : wires) {
        int size = count_component(network, wire[0], wire[0], wire[1]);
        answer = min(answer, abs(n - 2 * size));
    }
    return answer;
}

/* 원본 풀이
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    vector<vector<int>> network(n+1, vector<int> (n+1, 0));
    
    for (vector<int>& wire : wires) {
        network[wire[0]][wire[1]] = 1;
        network[wire[1]][wire[0]] = 1;
    }
    
    for (vector<int>& wire : wires) {
        queue<int> bfs;
        int size_a = 1;
        int size_b = 1;
        vector<int> visited(n+1, 0);
        network[wire[0]][wire[1]] = 0;
        network[wire[1]][wire[0]] = 0;
        
        bfs.push(wire[0]);
        while (!bfs.empty()) {
            int cur = bfs.front();
            bfs.pop();
            for (int i=1; i<=n; i++) {
                if (network[cur][i] && !visited[i]) {
                    bfs.push(i);
                    visited[i] = 1;
                    size_a++;
                }
            }
        }
        
        bfs.push(wire[1]);
        visited.assign(n+1, 0);
        while (!bfs.empty()) {
            int cur = bfs.front();
            bfs.pop();
            for (int i=1; i<=n; i++) {
                if (network[cur][i] && !visited[i]) {
                    bfs.push(i);
                    visited[i] = 1;
                    size_b++;
                }
            }
        }
        
        int diff = max(size_a, size_b) - min(size_a, size_b);
        if (answer > diff) answer = diff;
        
        network[wire[0]][wire[1]] = 1;
        network[wire[1]][wire[0]] = 1;
    }
    
    
    return answer;
}
*/
