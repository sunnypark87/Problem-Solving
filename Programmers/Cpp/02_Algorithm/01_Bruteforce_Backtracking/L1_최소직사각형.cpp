#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 개선 후 코드
// 값을 읽기만 하므로 const auto& 로 값을 복사하지 않고 사용
// if 분기를 max, min으로 짧게 사용할 수 있음

int solution(vector<vector<int>> sizes) {
    int max_w = 0, max_h = 0;

    for (const auto& card : sizes) {
        max_w = max(max_w, max(card[0], card[1]));
        max_h = max(max_h, min(card[0], card[1]));
    }

    return max_w * max_h;
}

// 개선 전 코드 
/*
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int max_w=0, max_h=0;
    
    for (auto size : sizes) {
        if (size[0] > size[1]) {
            if (max_w < size[0]) max_w = size[0];
            if (max_h < size[1]) max_h = size[1];
        }
        else {
            if (max_w < size[1]) max_w = size[1];
            if (max_h < size[0]) max_h = size[0];
        }
    }
    answer = max_w * max_h;
    
    return answer;
}
*/

int main(void) {
    vector<vector<vector<int>>> sizes_list = {
        { {60, 50}, {30, 70}, {60, 30}, {80, 40} }, 
        { {10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15} }, 
        { {14, 4}, {19, 6}, {6, 16}, {18, 7}, {7, 11} }
    };

    for (auto sizes : sizes_list) {
        solution(sizes);
    }

    return 0;
}
