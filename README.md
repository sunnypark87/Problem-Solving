# 📘 Problem Solving Solutions

알고리즘 문제 풀이 저장소입니다. 
백준(BOJ)과 프로그래머스의 C++ 및 JavaScript 풀이를 보관합니다.
C++를 주언어로 사용하며, **알고리즘 주제별**로 분류하여 관리하고 있습니다.

## 🏷️ Solved.ac Profile
[![Solved.ac Profile](http://mazassumnida.wtf/api/v2/generate_badge?boj=ggomabbang)](https://solved.ac/ggomabbang)

## 📂 Repository Structure

이 저장소는 **주제(Topic) > 세부 유형 > 난이도(Tier)** 순서로 구조화되어 있습니다.

```text
Baekjoon/Cpp
│
├── 01_DataStructure          # 자료구조
│   ├── 01_Linear                # Stack, Queue, Deque, List
│   ├── 02_Tree_Heap             # Heap(Priority Queue), Tree
│   ├── 03_Map_Set               # Hash Map, Set
│   └── 04_DisjointSet           # Union-Find
│
├── 02_Algorithm              # 주요 알고리즘
│   ├── 01_BruteForce_Backtracking
│   ├── 02_Sort
│   ├── 03_BinarySearch
│   ├── 04_Divide_Conquer        # 분할 정복
│   ├── 05_TwoPointer_SlidingWindow
│   ├── 06_Greedy
│   ├── 07_DP                    # Dynamic Programming 
│   └── 08_PrefixSum             # 누적 합
│
├── 03_Graph                  # 그래프 이론
│   ├── 01_BFS_DFS
│   ├── 02_ShortestPath          # Dijkstra, Floyd-Warshall
│   ├── 03_Tree
│   ├── 04_MST
│   └── 05_TopologicalSort
│
├── 04_Math                   # 수학 
│   ├── 01_NumberTheory          # 정수론 
│   ├── 02_Combinatorics         # 조합론
│   ├── 03_Arithmetic            # 산수
│   └── 04_Geometry              # 기하학
│
├── 05_String                 # 문자열 처리
└── 06_Implementation         # 구현 및 시뮬레이션
```

## 📑 Problem Categories

각 주제별 폴더로 바로 이동할 수 있는 링크입니다.

| 폴더명 | 주요 내용 | 비고 |
| :--- | :--- | :--- |
| **[01_DataStructure](./Baekjoon/Cpp/01_DataStructure)** | 자료구조 전반 | 스택, 큐, 힙, 맵, 집합 등 |
| **[02_Algorithm](./Baekjoon/Cpp/02_Algorithm)** | 핵심 알고리즘 | DP, 그리디, 이분탐색, 분할정복 |
| **[03_Graph](./Baekjoon/Cpp/03_Graph)** | 그래프 이론 | BFS, DFS, 최단경로, MST |
| **[04_Math](./Baekjoon/Cpp/04_Math)** | 수학 | 정수론, 조합론, 기하학 |
| **[05_String](./Baekjoon/Cpp/05_String)** | 문자열 | KMP, Trie, 문자열 파싱 |
| **[06_Implementation](./Baekjoon/Cpp/06_Implementation)** | 구현 | 시뮬레이션, 단순 구현 |

## 📝 Naming Convention

소스코드 파일명은 검색의 용이성을 위해 다음 규칙을 따릅니다.

* 규칙: `Tier_Number_Name.cpp`
    * `Tier`: 문제 난이도 (B: Bronze, S: Silver, G: Gold, P: Platinum)
    * `Number`: 백준 문제 번호
    * `Name`: 문제 이름 (띄어쓰기 없이 작성)

**예시:**
- `G5_2504_괄호의값.cpp`
- `S1_11286_절댓값힙.cpp`

## 문제 맵

| 사이트 / 언어 | 상세 분류 |
| --- | --- |
| Baekjoon / C++ | [문제 맵](./Baekjoon/Cpp/README.md) |
| Programmers / C++ | [문제 맵](./Programmers/Cpp/README.md) |
| Programmers / JavaScript | [문제 맵](./Programmers/Javascript/README.md) |

프로그래머스 파일명은 `L<Level>_<Name>.<ext>`를 사용한다.

## 주요 개념 요약

- 그래프: 같은 이동 비용의 최단거리는 BFS로 구하며, 큐에 넣기 전에 방문 표시한다. [상세 노트](./Programmers/Cpp/03_Graph/01_BFS_DFS/README.md)
- 완전 탐색: 반복 패턴을 조회하거나 백트래킹으로 후보를 열거하며, 중복 선택과 선행 0을 가지치기한다. 공유하는 방문 상태는 재귀 호출 뒤 복원한다. 사전 순 탐색에서는 목표보다 큰 접두사를 가지치기할 수 있다. [상세 노트](./Programmers/Cpp/02_Algorithm/01_Bruteforce_Backtracking/README.md)
- 트리 분할: 간선 하나를 제거한 뒤 한쪽 연결 요소 크기만 구하면 나머지는 전체에서 뺄 수 있다. [상세 노트](./Programmers/Cpp/03_Graph/01_BFS_DFS/README.md)

- DP: 상태에 최적값을 저장하고 의존하는 상태가 계산된 순서로 갱신한다. [상세 노트](./Programmers/Cpp/02_Algorithm/07_DP/README.md)
