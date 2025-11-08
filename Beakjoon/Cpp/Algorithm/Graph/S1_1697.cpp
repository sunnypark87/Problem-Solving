#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 시간 초과 어떻게 하지?
void move(vector<int>& place, int src, int& dest, int move_count, int prev_move_type) {
    if (src < 0 || src > 100000) return;
    if (move_count > place[dest]) return;
    if (src == dest) {
        if (move_count < place[dest]) {
            place[dest] = move_count;
        }
    } else if (src > dest) {
        int total_move = move_count + (src - dest);
        if (total_move < place[dest]) place[dest] = total_move;
    } else {
        if (prev_move_type == 0 || prev_move_type == 1) {
            move(place, src*2, dest, move_count+1, 1);
            move(place, src+1, dest, move_count+1, 2);
            move(place, src-1, dest, move_count+1, 3);
        } else if (prev_move_type == 2) {
            move(place, src*2, dest, move_count+1, 1);
            move(place, src+1, dest, move_count+1, 2);
        } else if (prev_move_type == 3) {
            move(place, src*2, dest, move_count+1, 1);
            move(place, src-1, dest, move_count+1, 3);
        }
    }
}

int main(void) {
    int n, k;
    int cur_pos, step;
    vector<int> place(100001, 100002);
    queue<int> bfs;

    cin >> n >> k;

    cur_pos = n;
    step = 0;
    place[cur_pos] = step;
    bfs.push(cur_pos);
    while (!bfs.empty()) {
        if (cur_pos-1 >= 0) {
            if (place[cur_pos]+1 < place[cur_pos-1]) {
                place[cur_pos-1] = place[cur_pos]+1;
                bfs.push(cur_pos-1);
            }
        }
        if (cur_pos+1 <= 100000) {
            if (place[cur_pos]+1 < place[cur_pos+1]) {
                place[cur_pos+1] = place[cur_pos]+1;
                bfs.push(cur_pos+1);
            }   
        }
        if (cur_pos*2 <= 100000) {
            if (place[cur_pos]+1 < place[cur_pos*2]) {
                place[cur_pos*2] = place[cur_pos]+1;
                bfs.push(cur_pos*2);
            }   
        }
        bfs.pop();
        cur_pos = bfs.front();
    }
    
    cout << place[k] << '\n';

    return 0;
}
