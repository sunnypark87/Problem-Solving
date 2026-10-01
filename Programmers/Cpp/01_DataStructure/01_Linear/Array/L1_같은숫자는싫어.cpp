#include <vector>
#include <iostream>

using namespace std;

// 개선 답안
// 1. 결과의 마지막 값과 현재 값을 비교하여 연속된 중복만 건너뜀
// -> 별도 변수 필요 x
// 2. answer.empty()를 먼저 확인해서 빈 배열도 처리 가능
// 시간/공간 복잡도 : O(n) / O(n)
// 3. int는 값으로 순회해도 충분함
vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (const int element : arr) {
        if (answer.empty() || answer.back() != element)
            answer.push_back(element);
    }
    return answer;
}

// 내 답안
/*
vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int prev = arr[0];

    for (const int& element : arr) {
        if (prev != element) {
            answer.push_back(prev);
            prev = element;
        }
    }
    answer.push_back(prev);

    return answer;
}
*/
