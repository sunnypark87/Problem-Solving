#include <iostream>
#include <map>
#include <string>
using namespace std;
/*
< 코드 개선 방안 >
- 입력 시 [] operator 사용
- map 대신 해시 맵(unordered_map)을 사용 -> 입력을 빠르게 처리할 수 있음

*/
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, answer_count;
    string input, answer;
    map<string, int> words;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> input;
        if (!words.count(input)) {
            words.insert({input, 1});
        }
        else {
            words[input]++;
        }
    }

    answer_count = 0;
    for (auto &word : words) {
        if (word.second >= answer_count) {
            answer = word.first;
            answer_count = word.second;
        }
    }

    cout << answer << ' ' << answer_count << '\n';
    
    return 0;
}