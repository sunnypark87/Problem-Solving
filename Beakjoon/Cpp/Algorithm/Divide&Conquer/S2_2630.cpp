#include <iostream>
#include <vector>
using namespace std;

int blue = 0;
int white = 0;

int check_same(vector<vector<int>> &paper, int paper_size, int x, int y) {
    int is_same, start_color; 
    start_color = paper[y][x];
    is_same = 1;
    for (int i=0; i<paper_size; i++) {
        for (int j=0; j<paper_size; j++) {
            if (paper[y+i][x+j] != start_color) {
                is_same = 0;
                break;
            }
        }
        if (is_same == 0) break;
    }
    return is_same;
}

void check_paper(vector<vector<int>> &paper, int paper_size, int x, int y) {
    if (paper_size == 1) {
        if (paper[y][x] == 0) white++;
        else blue++;
        return;
    }

    int n = paper_size / 2;
    int start_color;

    start_color = paper[y][x]; 
    if (check_same(paper, n, x, y) == 1) {
        if (start_color == 0) white++;
        else blue++;
    }
    else check_paper(paper, n, x, y);

    start_color = paper[y][x+n];
    if (check_same(paper, n, x+n, y) == 1) {
        if (start_color == 0) white++;
        else blue++;
    }
    else check_paper(paper, n, x+n, y);

    start_color = paper[y+n][x];
    if (check_same(paper, n, x, y+n) == 1) {
        if (start_color == 0) white++;
        else blue++;
    }
    else check_paper(paper, n, x, y+n);

    start_color = paper[y+n][x+n];    
    if (check_same(paper, n, x+n, y+n) == 1) {
        if (start_color == 0) white++;
        else blue++;
    }
    else check_paper(paper, n, x+n, y+n);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input;

    cin >> n;
    vector<vector<int>> paper(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> input;
            paper[i][j] = input;
        }
    }

    int start_color = paper[0][0]; 
    if (check_same(paper, n, 0, 0) == 1) {
        if (start_color == 0) white++;
        else blue++;
    }
    else check_paper(paper, n, 0, 0);

    cout << white << '\n' << blue << '\n';
    
    return 0;
}