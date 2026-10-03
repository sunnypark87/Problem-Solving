#include <vector>
#include <queue>
#include <utility>
using namespace std;

// 풀이 리뷰 및 개선
/*
- 상하좌우 이동 비용이 모두 같으므로 BFS에서 처음 방문한 칸의 거리가 최단거리다.
  큐에 넣기 전에 방문 표시한 원본 방식은 적절하다.

- 시간/공간복잡도
  N은 행 수, M은 열 수. 각 칸을 최대 한 번 큐에 넣고 네 방향을 확인한다.
  원본과 개선 모두 -> 시간 : O(NM) / 보조 공간 : O(NM) (거리 배열과 큐)
  입력 맵 자체는 O(NM), maps의 값 전달로 생기는 복사 공간도 O(NM)이다.
  목적지에서 조기 반환하면 남은 탐색을 줄이지만 최악 복잡도는 같다.

- 오류 발생 가능성 / 핵심 수정
  공식 문제 조건에서 뚜렷한 정답 오류를 찾지 못했다.
  지나간 칸 수를 세므로 시작 거리는 1, 미방문 거리는 -1로 두는 것이 맞다.
  BFS는 거리 순으로 꺼내므로 목적지를 꺼내면 바로 반환해도 된다.

- 코드 구조/간결성
  visited를 distance로 변경 -> 방문 여부와 거리 저장 역할을 함께 드러낸다.
  행/열 좌표를 row/col로 표현하고, 다음 좌표는 반복문 안에서 선언한다.
  고정된 네 방향은 배열로 표현하고, 범위 밖 좌표는 continue로 먼저 제외한다.
  answer 없이 거리를 직접 반환하고, 큐가 빌 때까지 도착하지 못하면 -1을 반환한다.
*/

int solution(vector<vector<int> > maps)
{
    const int n = maps.size();
    const int m = maps[0].size();
    const int move_row[4] = {1, 0, -1, 0};
    const int move_col[4] = {0, 1, 0, -1};

    vector<vector<int>> distance(n, vector<int>(m, -1));
    queue<pair<int, int>> bfs;
    distance[0][0] = 1;
    bfs.push({0, 0});

    while (!bfs.empty()) {
        const auto [row, col] = bfs.front();
        bfs.pop();

        if (row == n - 1 && col == m - 1) return distance[row][col];

        for (int i = 0; i < 4; ++i) {
            const int next_row = row + move_row[i];
            const int next_col = col + move_col[i];
            if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
            if (maps[next_row][next_col] == 0 || distance[next_row][next_col] != -1) continue;

            distance[next_row][next_col] = distance[row][col] + 1;
            bfs.push({next_row, next_col});
        }
    }
    return -1;
}

// 원본 풀이
/*
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    int cur_x = 0, cur_y = 0, next_x, next_y;
    vector<int> move_x = { 1, 0, -1, 0 };
    vector<int> move_y = { 0, 1, 0, -1 };
    
    vector<vector<int>> visited(n, vector<int>(m, -1));
    queue<pair<int, int>> bfs;
    
    bfs.push({cur_x, cur_y});
    visited[cur_x][cur_y] = 1;
    while (!bfs.empty()) {
        cur_x = bfs.front().first;
        cur_y = bfs.front().second;
        bfs.pop();
        for (int i=0; i<4; i++) {
            next_x = cur_x + move_x[i];
            next_y = cur_y + move_y[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) 
                if (maps[next_x][next_y] && visited[next_x][next_y] == -1) {
                    visited[next_x][next_y] = visited[cur_x][cur_y] + 1;
                    bfs.push({next_x, next_y});
                }
        }
    }
    
    answer = visited[n-1][m-1];
    
    return answer;
}
*/
