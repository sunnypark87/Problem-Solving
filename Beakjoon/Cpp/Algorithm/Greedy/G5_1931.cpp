#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, start, end;
    int prev_start;
    int answer_start, answer_end, answer;
    struct Compare_first {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second > b.second;
            }
        }
    };
    struct Compare_second {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            else {
                return a.first < b.first;
            }
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare_first> min_pq;
    vector<pair<int, int>> min_vector;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> start >> end;
        min_pq.push(make_pair(start, end));
    }

    prev_start = -1;
    while(!min_pq.empty()) {
        if (prev_start != min_pq.top().first) {
            min_vector.push_back(make_pair(min_pq.top().first, min_pq.top().second));
        }
        if (min_pq.top().first != min_pq.top().second) {
            prev_start = min_pq.top().first;
        }
        min_pq.pop();
    }

    sort(min_vector.begin(), min_vector.end(), Compare_second{});

    answer_start = 0;
    answer_end = 0;
    answer = 0;
    for (auto& meet : min_vector) {
        cout << "first : " << meet.first << " second : " << meet.second << ' ';
        if (meet.first >= answer_end) {
            cout << " answer_end : " << answer_end << '\n';
            answer_end = meet.second;
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}