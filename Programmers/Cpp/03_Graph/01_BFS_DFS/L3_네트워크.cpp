#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 풀이 리뷰 및 개선
/*
- 인접 행렬을 BFS로 탐색하며 연결 요소(네트워크)의 개수를 세는 풀이
  방문하지 않은 정점에서 탐색을 시작할 때 network를 증가시키는 방식은 적절하다.

- 시간/공간복잡도
  큐에서 꺼낼 때 방문 표시 -> 대기 중인 노드 중복 가능 -> 중복 항목도 전체 탐색
  -> 시간 : O(N^2 + NQ) / 공간 : O(N + Q)
  -> 조밀한 그래프에서는 Q(큐 삽입 횟수)가 지수적으로 커질 가능성
  큐에 넣을 때 방문 표시 -> 노드 한 번만 삽입
  -> 시간 : O(N^2) / 공간 : O(N)

- 오류 발생 가능성 / 핵심 수정
  큐에 넣을 때 방문 표시를 하지 않으면 중복 삽입 문제가 발생함
  시작 노드와 이웃 노드 모두 큐에 넣기 전에 방문 표시를 해야 함 
  중복 탐색으로 시간 초과, 메모리 초과 발생 가능 

- 코드 구조/간결성
  큐의 맨 앞 정점을 current에 저장 후 pop해서 사용
  내부 반복문의 i를 역할을 드러내는 이름으로 사용
  networks 대신 visited로 충분 (네트워크 번호를 사용하지 않음)
  answer와 network 중 하나만 사용 (같은 값을 담음)
  i != bfs.front()는 불필요 (방문 표시가 되어 있으면 자기 자신도 제외됨)
*/

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    queue<int> bfs;

    for (int start = 0; start < n; ++start) {
        if (visited[start]) continue;

        ++answer;
        visited[start] = true;
        bfs.push(start);

        while (!bfs.empty()) {
            int current = bfs.front();
            bfs.pop();

            for (int next = 0; next < n; ++next) {
                if (computers[current][next] && !visited[next]) {
                    visited[next] = true;
                    bfs.push(next);
                }
            }
        }
    }
    return answer;
}

int main(void) {

    vector<int> n = { 3, 3 };
    vector<vector<vector<int>>> computers = {
      {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}},
      {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}  
    };

    for (int i=0; i<n.size(); i++) {
        cout << solution(n[i], computers[i]);
    }

    return 0;
}

/* 
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    int network = 0;
    
    vector<int> networks(n, 0);
    queue<int> bfs;
    
    for (int i=0; i<n; i++) {
        if (!networks[i]) {
            bfs.push(i);
            network++;
        }
        while (!bfs.empty()) {
            networks[bfs.front()] = network;
            for (int i=0; i<n; i++) {
                if (i != bfs.front() && computers[bfs.front()][i] && !networks[i]) {
                    networks[bfs.front()] = network;
                    bfs.push(i);
                }
            }
            bfs.pop();
        }
    }
    
    answer = network;
    
    return answer;
}
*/ 
