#include <iostream>
#include <sstream>
#include <string>
#include <deque>
using namespace std;

deque<int> split(const string& s, char delimiter) {
    deque<int> tokens;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delimiter)) {
        tokens.push_back(stoi(item));
    }
    return tokens;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, r_count, is_error;
    string p, x, modified_x;
    deque<int> nums;
    
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> p >> n >> x;
        r_count = 0;
        is_error = 0;
        nums.clear();
        if (n != 0) {
            modified_x = x.substr(1, x.length()-2);
            modified_x.push_back('\n');
            nums = split(modified_x, ',');
        }
        for (auto command : p) {
            if (command == 'R') {
                r_count++;
            }
            else {
                if (nums.size() == 0) {
                    is_error = 1;
                    break;
                }
                if (r_count % 2 == 0) {
                    nums.pop_front();
                }
                else {
                    nums.pop_back();
                }
            }
        }
        if (is_error) {
            cout << "error\n";
        }
        else {
            cout << '[';
            if (r_count % 2 == 0) {
                while (!nums.empty()) {
                    if (nums.size() == 1) {
                        cout << nums.front(); 
                    }
                    else {
                        cout << nums.front() << ',';
                    }
                    nums.pop_front();
                }
            }
            else {
                while (!nums.empty()) {
                    if (nums.size() == 1) {
                        cout << nums.back(); 
                    }
                    else {
                        cout << nums.back() << ',';
                    }
                    nums.pop_back();
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}