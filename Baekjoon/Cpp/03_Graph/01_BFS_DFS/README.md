## BFS vs Backtracking
### BFS
- 최단 거리, 최소 횟수 보장
- Queue 사용
- 대표 문제 : 미로 찾기, 토마토, 숨바꼭질, DSLR
- 메모리 초과 주의
### Backtracking
- 모든 경우의 수 탐색
- 재귀함수 or Stack 사용
- 대표 문제 : N-Queen, N과 M, 부분수열의 합
- 가지치기(Pruning) 없으면 시간 초과 
---
## BFS 구현 시 고려사항
- visited 배열 만들기
    큐에 넣는 순간 `visited = true` 처리를 해줘야 함. (중복 삽입 방지)
    메모리/시간 초과 발생의 주요 원인
- 경로 추적 (Path Reconstruction)
    큐에 string이나 vector를 통째로 넣으면 안됨 -> 메모리 초과
    부모 노드나 명령어 등을 `visited` 배열에 저장해서 목표 도달 시 역추적(Traceback)

