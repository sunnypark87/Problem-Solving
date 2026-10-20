# Graph (그래프)

그래프 탐색, 최단 경로, MST, 위상 정렬.

## 📝 학습 노트

> 이 디렉터리의 문제를 풀면서 얻은 인사이트가 누적됩니다.
> 코드 리뷰 시 핵심 takeaway가 아래에 추가됩니다.

## 문제 맵

| 분류 | 주요 내용 |
| --- | --- |
| [BFS / DFS](./01_BFS_DFS/README.md) | 연결 요소, 격자 최단거리 |
| [최단 경로](./02_ShortestPath/README.md) | 가중치 그래프의 최단 경로 |
| [트리](./03_Tree/README.md) | 트리 탐색 |
| [MST](./04_MST/README.md) | 최소 신장 트리 |
| [위상 정렬](./05_TopologicalSort/README.md) | 선후 관계 |

## 주요 개념 요약

- 같은 이동 비용의 최단거리는 BFS로 구한다. 방문 처리와 격자 거리 계산은 [BFS / DFS 노트](./01_BFS_DFS/README.md)를 참고한다.
- 트리의 간선 절단은 한쪽 크기 s로 `abs(N-2*s)`를 평가한다. 인접 리스트 BFS와 시작점 방문 처리는 [BFS / DFS 노트](./01_BFS_DFS/README.md)를 참고한다.
