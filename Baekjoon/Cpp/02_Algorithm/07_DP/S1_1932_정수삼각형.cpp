#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 수정 후 코드 */
// 1차원 배열에서 가독성을 위해 2차원 배열로 수정
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input;
    vector<vector<int>> triangle(501, vector<int>(501, 0));
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cin >> triangle[i][j];
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
    }

    int answer = 0;
    for (int i=1; i<=n; i++) {
        if (answer < triangle[n][i]) answer = triangle[n][i];
    }

    cout << answer << '\n';
    return 0;
}

/* 수정 전 코드 */
/*
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input, index=1;
    vector<int> triangle(125251, 0);
    cin >> n;

    cin >> input;
    triangle[index++] = input;
    for (int depth=1; depth<n; depth++) {
        for (int i=depth; i>=0; i--) {
            cin >> input;
            if (i == depth) triangle[index] = triangle[index-depth] + input;
            else if (i == 0) triangle[index] = triangle[index-depth-1] + input;
            else {
                triangle[index] = max(triangle[index-depth-1], triangle[index-depth]) + input;
            }
            index++;
        }
    }

    index--;
    int answer = 0;
    for (int i=0; i<n; i++) {
        if (answer < triangle[index]) answer = triangle[index];
        index--;
    }

    cout << answer << '\n';

    return 0;
}
*/