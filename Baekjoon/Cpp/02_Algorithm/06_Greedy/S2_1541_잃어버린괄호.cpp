#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// 개선 알고리즘 : 한 번이라도 마이너스가 나오면 그 뒤는 다 마이너스 처리해도 됨 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int sum, answer;
    char input;
    string num;
    vector<int> nums;
    vector<char> op;
    queue<int> temp;
    num.clear();
    while (cin >> input) {
        if (input == '-' || input == '+') {
            nums.push_back(stoi(num));
            op.push_back(input);
            num.clear();
        }
        else {
            num += input;
        }
    }
    nums.push_back(stoi(num));

    sum = nums[0];
    for (int i=0; i<op.size(); i++) {
        if (op[i] == '+') {
            sum += nums[i+1]; 
        }
        else {
            temp.push(sum);
            sum = nums[i+1];
        }
    }
    temp.push(sum);

    answer = temp.front();
    temp.pop();
    while (!temp.empty()) {
        answer -= temp.front();
        temp.pop();
    }

    cout << answer << '\n';

    return 0;
}