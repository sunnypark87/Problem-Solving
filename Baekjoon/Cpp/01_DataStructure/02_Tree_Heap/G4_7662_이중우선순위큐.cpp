#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

// multiset을 사용하면 priority queue를 사용하지 않고도 바로 풀 수 있음
// 아래의 방법은 Lazy Deletion이라고 함

int main(void) {
    int t, k;
    long long num;
    char command;
    priority_queue<long long> max_pq;
    struct Compare {
        bool operator()(long long a, long long b) const {
            return a > b;
        }
    };
    priority_queue<long long, vector<long long>, Compare> min_pq;
    unordered_multiset<long long> nums;

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> k;
        for (int j=0; j<k; j++) {
            cin >> command;
            if (command == 'I') {
                cin >> num;
                min_pq.push(num);
                max_pq.push(num);
                nums.insert(num);
            }
            else {
                cin >> num;
                if (!nums.empty()) {
                    if (num == 1) {
                        auto it = nums.find(max_pq.top());
                        while (it == nums.end()) {
                            max_pq.pop();
                            it = nums.find(max_pq.top());
                        }
                        nums.erase(it);
                        max_pq.pop();
                    }
                    else {
                        auto it = nums.find(min_pq.top());
                        while (it == nums.end()) {
                            min_pq.pop();
                            it = nums.find(min_pq.top());
                        }
                        nums.erase(it);
                        min_pq.pop();
                    }
                }
                if (nums.empty()) {
                    while (!max_pq.empty()) {
                        max_pq.pop();
                    }
                    while (!min_pq.empty()) {
                        min_pq.pop();
                    }
                }
            }
        }
        if (nums.empty()) {
            cout << "EMPTY\n";
        }
        else {
            auto it = nums.find(max_pq.top());
            while (it == nums.end()) {
                max_pq.pop();
                it = nums.find(max_pq.top());
            }
            it = nums.find(min_pq.top());
            while (it == nums.end()) {
                min_pq.pop();
                it = nums.find(min_pq.top());
            }
            cout << max_pq.top() << ' ' << min_pq.top() << '\n';
        }
        while (!max_pq.empty()) {
            max_pq.pop();
        }
        while (!min_pq.empty()) {
            min_pq.pop();
        }
        nums.clear();
    }
    
    return 0;
}