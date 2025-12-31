#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 트리는 visited가 필요하지 않음

vector<vector<char>> tree(26, vector<char>(2, '.'));
string preorder="", inorder="", postorder="";

void traversal(char cur) {
    preorder += cur;
    int cur_i = cur - 'A';
    if (tree[cur_i][0] != '.') {
        traversal(tree[cur_i][0]);
    }
    inorder += cur;
    if (tree[cur_i][1] != '.') {
        traversal(tree[cur_i][1]);
    }
    postorder += cur;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    char input, cur; 
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> input;
        cin >> tree[input-'A'][0] >> tree[input-'A'][1];
    }

    traversal('A');

    cout << preorder << '\n';
    cout << inorder << '\n';
    cout << postorder << '\n';

    return 0;
}