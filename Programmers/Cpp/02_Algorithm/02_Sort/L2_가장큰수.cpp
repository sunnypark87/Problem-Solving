#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 개선 후 코드 
// 처음부터 스트링으로 계산
// C++ 람다 표현식


string solution(vector<int> numbers) {
    vector<string> nums;
    string answer = "";
    
    for (int i=0; i<numbers.size(); i++) {
        nums.push_back(to_string(numbers[i]));
    }

    sort(nums.begin(), nums.end(), 
        [](const string& a, const string& b) {
            return a + b > b + a;
        }
    );

    if (nums.front() == "0") return "0";
    
    for (string num : nums) {
        answer += num;
    }
    
    return answer;
}

int main(void) {
    string answer;
    vector<vector<int>> numbers = {
        { 6, 10, 2 },
        { 3, 30, 34, 5, 9 }  
    };

    for (int i=0; i<numbers.size(); i++) {
        answer = solution(numbers[i]);
        cout << answer << '\n';
    }

    return 0;
}

// 개선 전 코드 

bool comp(int a, int b) {
    int digit_a = 1, digit_b = 1;
    int comp_a, comp_b;
    int dividend = 10;
    bool result;
    while (true) {
        if (a / dividend == 0) break;
        digit_a++;
        dividend *= 10;
    }
    dividend = 10;
    while (true) {
        if (b / dividend == 0) break;
        digit_b++;
        dividend *= 10;
    }
    comp_a = a * (int)(pow(10, digit_b)) + b;
    comp_b = b * (int)(pow(10, digit_a)) + a;

    return comp_a > comp_b;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comp);
    
    for (int i=0; i<numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    
    return answer;
}
