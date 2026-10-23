#include <vector>
#include <algorithm>

using namespace std;

// 풀이 리뷰 및 개선
/*
- 각 칸을 꼭대기에서 그 칸까지의 최대 경로 합으로 갱신하는 DP 풀이.
  이전 행의 가능한 부모 중 큰 누적 합을 선택하므로 마지막 행의 최댓값이 정답이다.

- 시간/공간복잡도
  N = 삼각형의 높이. 전체 N(N+1)/2개 칸 갱신 + 마지막 행 N개 탐색
  -> 원본·개선 모두 시간 : O(N^2) / 별도 보조 공간 : O(1)
  입력 자체는 O(N^2). 값 전달 인자를 복사하는 비용까지 포함하면
  복사 시간 O(N^2), 함수가 보유하는 triangle 공간 O(N^2)가 필요하다.

- 알고리즘 효율성 평가
  공식 제한 N <= 500에서 최대 125,250개 칸을 처리하므로 적절하다.
  별도 DP 배열 없이 인자 사본을 재사용하며, 모든 입력 칸을 확인하는 O(N^2) 풀이.
  max_element 적용은 가독성 개선이며 점근적 시간·공간복잡도는 동일하다.
  공식 설명에 구체적인 시간·메모리 제한은 표시되어 있지 않다.

- 다른 알고리즘 / 풀이 방법
  아래에서 위로 현재 값 + max(왼쪽 자식, 오른쪽 자식)을 저장하면 꼭대기가 답이다.
  두 자식이 항상 존재하므로 경계 분기가 없고 시간 O(N^2), 별도 보조 공간 O(1).
  현재 방식도 효율적이고 각 칸까지의 최댓값이라는 의미가 명확하므로 유지한다.
  1차원 DP는 O(N) 보조 공간으로 이전 행만 저장할 수 있다.
  위에서 아래로 진행할 때 오른쪽부터 갱신해야 아직 필요한 이전 행 값을 보존한다.
  다만 현재 값 전달 시그니처에서는 인자 복사 공간 O(N^2)는 그대로 남는다.

- 오류 발생 가능성 / 핵심 수정
  공식 조건에서 뚜렷한 오류는 없다. 높이가 1이어도 마지막 행이 존재한다.
  원소가 모두 0 이상이므로 원본의 answer = 0도 올바르다.
  최대 합은 500 * 9,999 = 4,999,500으로 32비트 int 범위 안에 들어간다.
  왼쪽 끝은 바로 위, 오른쪽 끝은 왼쪽 위만 참조하는 경계 처리가 필요하다.

- 코드 구조/간결성
  마지막 행은 triangle.back(), 최댓값은 *max_element(...)로 표현한다.
  별도 answer와 최댓값 탐색 반복문을 제거하고 DP 점화식은 유지한다.
  행 i의 열은 0~i이므로 반복 범위와 오른쪽 끝 조건을 i로 표현한다.

- 문제 조건 출처
  https://school.programmers.co.kr/learn/courses/30/lessons/43105
*/

int solution(vector<vector<int>> triangle) {
    const int height = static_cast<int>(triangle.size());

    for (int i = 1; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) triangle[i][j] += triangle[i - 1][j];
            else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
            else triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
    }

    return *max_element(triangle.back().begin(), triangle.back().end());
}

// 원본 풀이
/*
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    
    for (int i=1; i<height; i++) {
        for (int j=0; j<triangle[i].size(); j++) {
            if (j == 0) triangle[i][j] += triangle[i-1][j];
            else if (j == triangle[i].size() - 1) triangle[i][j] += triangle[i-1][j-1];
            else triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]); 
        }
    }
    
    for (int i=0; i<triangle[height-1].size(); i++) {
        answer = max(answer, triangle[height-1][i]);
    }
    
    return answer;
}
*/
