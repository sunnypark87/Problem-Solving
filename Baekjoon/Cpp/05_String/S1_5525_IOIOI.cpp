#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    int n, m, prev_mode, mode, length, answer;
    char prev, input;
    vector<int> p_number;

    cin >> n >> m;
    mode = 0;
    length = 0;
    for (int i=0; i<m; i++) {
        cin >> input;
        if (mode == 0) {
            if (input == 'I') {
                mode = 1;
            }
            prev_mode = 0;
        } 
        else if (mode == 1) {
            if (input == 'O') {
                mode = 2;
            }
            prev_mode = 1;
        }
        else if (mode == 2) {
            if (input == 'I') {
                length++;
                mode = 3;
            }
            else {
                if (prev_mode == 3) {
                    p_number.push_back(length);
                    length = 0;
                }
                mode = 0;
            }
            prev_mode = 2;
        }
        else {
            if (input == 'I') {
                p_number.push_back(length);
                length = 0;
                mode = 1;
            }
            else {
                mode = 2;
            }
            prev_mode = 3;
        }
    }
    p_number.push_back(length);

    answer = 0;
    for (auto num : p_number) {
        if ((num - n + 1) > 0) {
            answer += num-n+1;
        }
    }
    cout << answer << '\n';


    return 0;
}