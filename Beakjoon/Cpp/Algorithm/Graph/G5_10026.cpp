#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    int n, color_int, answer_1, answer_2, cur_x, cur_y;
    char color;
    queue<pair<int, int>> bfs;

    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, 0)); 
    vector<vector<int>> first_area(n, vector<int>(n, 0));
    vector<vector<int>> second_area(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    answer_1 = 0;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (first_area[i][j] == 0) {
                color = grid[i][j];
                
                if (color == 'R') color_int = 1;
                else if (color == 'G') color_int = 2;
                else color_int = 3;
                first_area[i][j] = color_int;
                answer_1++;
                bfs.push(make_pair(i, j));
            }
            while (!bfs.empty()) {
                cur_x = bfs.front().first;
                cur_y = bfs.front().second;
                
                if (cur_x-1 >= 0 && grid[cur_x-1][cur_y] == color && first_area[cur_x-1][cur_y] == 0) {
                    first_area[cur_x-1][cur_y] = color_int;
                    bfs.push(make_pair(cur_x-1, cur_y));
                }
                if (cur_y-1 >= 0 && grid[cur_x][cur_y-1] == color && first_area[cur_x][cur_y-1] == 0) {
                    first_area[cur_x][cur_y-1] = color_int;
                    bfs.push(make_pair(cur_x, cur_y-1));
                }
                if ((cur_x+1 < n) && (grid[cur_x+1][cur_y] == color) && (first_area[cur_x+1][cur_y] == 0)) {
                    first_area[cur_x+1][cur_y] = color_int;
                    bfs.push(make_pair(cur_x+1, cur_y));
                }
                if (cur_y+1 < n && grid[cur_x][cur_y+1] == color && first_area[cur_x][cur_y+1] == 0) {
                    first_area[cur_x][cur_y+1] = color_int;
                    bfs.push(make_pair(cur_x, cur_y+1));
                }
                bfs.pop();
            } 
        }
    }

    answer_2 = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (second_area[i][j] == 0) {
                color_int = first_area[i][j];
                if (color_int == 2) color_int = 1;
                second_area[i][j] = color_int;
                answer_2++;
                bfs.push(make_pair(i, j));
            }
            while (!bfs.empty()) {
                cur_x = bfs.front().first;
                cur_y = bfs.front().second;
                if (cur_x-1 >= 0 && second_area[cur_x-1][cur_y] == 0) {
                    if (color_int == 1 && (first_area[cur_x-1][cur_y] == 1 || first_area[cur_x-1][cur_y] == 2)) {
                        second_area[cur_x-1][cur_y] = color_int;
                        bfs.push(make_pair(cur_x-1, cur_y));
                    }
                    else if (color_int == 3 && first_area[cur_x-1][cur_y] == 3) {
                        second_area[cur_x-1][cur_y] = color_int;
                        bfs.push(make_pair(cur_x-1, cur_y));
                    }
                }
                if (cur_y-1 >= 0 && second_area[cur_x][cur_y-1] == 0) {
                    if (color_int == 1 && (first_area[cur_x][cur_y-1] == 1 || first_area[cur_x][cur_y-1] == 2)) {
                        second_area[cur_x][cur_y-1] = color_int;
                        bfs.push(make_pair(cur_x, cur_y-1));
                    }
                    else if (color_int == 3 && first_area[cur_x][cur_y-1] == 3) {
                        second_area[cur_x][cur_y-1] = color_int;
                        bfs.push(make_pair(cur_x, cur_y-1));
                    }
                }
                if (cur_x+1 < n && second_area[cur_x+1][cur_y] == 0) {
                    if (color_int == 1 && (first_area[cur_x+1][cur_y] == 1 || first_area[cur_x+1][cur_y] == 2)) {
                        second_area[cur_x+1][cur_y] = color_int;
                        bfs.push(make_pair(cur_x+1, cur_y));
                    }
                    else if (color_int == 3 && first_area[cur_x+1][cur_y] == 3) {
                        second_area[cur_x+1][cur_y] = color_int;
                        bfs.push(make_pair(cur_x+1, cur_y));
                    }
                }
                if (cur_y+1 < n && second_area[cur_x][cur_y+1] == 0) {
                    if (color_int == 1 && (first_area[cur_x][cur_y+1] == 1 || first_area[cur_x][cur_y+1] == 2)) {
                        second_area[cur_x][cur_y+1] = color_int;
                        bfs.push(make_pair(cur_x, cur_y+1));
                    }
                    else if (color_int == 3 && first_area[cur_x][cur_y+1] == 3) {
                        second_area[cur_x][cur_y+1] = color_int;
                        bfs.push(make_pair(cur_x, cur_y+1));
                    }
                }
                bfs.pop();
            } 
        }
    }

    cout << answer_1 << ' ' << answer_2 << '\n';



    return 0;
}