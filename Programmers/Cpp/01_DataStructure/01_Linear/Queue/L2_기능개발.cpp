#include <iostream>
#include <algorithm>
#include <cstddef>
#include <vector>

using namespace std;


// 코드 개선
/*
 * 시간 복잡도: O(n). 결과와 입력 복사를 제외한 보조 공간: O(1).
 * 현재 매개변수는 값 전달이므로 입력 벡터 복사까지 포함하면 공간 O(n).
 * 1. 배포 가능 날짜 계산 방법 = (남은 작업량 + 속도 - 1) / 속도
 * 2. 앞에서부터 순서대로 보면 됨 -> queue 필요 x
 * 3. 진행도가 100 이상일 수 있으면 남은 작업량을 0으로 제한
 * 4. deploy_count 대신 answer.back()에 현재 작업 개수를 바로 기록 
 *    -> 관리할 상태와 분기를 줄일 수 있음
 * 
 * [이 논리를 비슷한 문제에 적용하는 순서]
 * - 각 항목의 독립적인 완료 시점(시간/비용) 계산
 * - 순서 제약이 있음 -> 현재 항목에 영향을 주는 상태 찾기
 *   -> 앞 기능의 배포일 (= 누적 최댓값)
 * - 결과를 묶는 기준 잡기 
 */
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int release_day = 0;

    for (int i = 0; i < progresses.size(); ++i) {
        const int remain_work = max(0, 100 - progresses[i]);
        const int days = (remain_work + speeds[i] - 1) / speeds[i];

        if (answer.empty() || days > release_day) {
            release_day = days;
            answer.push_back(1);
        }
        else {
            answer.back()++;
        }
    }

    return answer;
}

int main(void) {

    vector<vector<int>> progresses = {
        {93, 30, 55},
        {95, 90, 99, 99, 80, 99}
    };
    vector<vector<int>> speeds = {
        {1, 30, 5}, 
        {1, 1, 1, 1, 1, 1}
    };

    for (int i=0; i<progresses.size(); i++) {
        for (int answer : solution(progresses[i], speeds[i])) {
            cout << answer << ' ';
        };
        cout << '\n';
    }

    return 0;
}

// 작성한 코드
/* 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int deploy_count = 0;
    int deploy_date = 0;
    int remain_work, work_speed, remain_date;

    queue<pair<int, int>> works;
    for (int i=0; i<progresses.size(); i++) {
        works.push({progresses[i], speeds[i]});
    }
    
    while(!works.empty()) {
        remain_work = works.front().first;
        work_speed = works.front().second;
        remain_date = (99 - remain_work) / work_speed;
        if (deploy_date < remain_date) {
            deploy_date = remain_date;
            if (deploy_count != 0)
                answer.push_back(deploy_count);
            deploy_count = 0;
        }
        deploy_count++;
        works.pop();
    }
    answer.push_back(deploy_count);
    
    return answer;
}
*/
