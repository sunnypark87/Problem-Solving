#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 구조체를 사용하지 않는 것이 정석?
// 굳이 입력 부분에서 1을 넣어줄 필요는 없음

struct node {
    int prev_node = 0;
    vector<int> next_node;
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, prev_num, cur_num;
    cin >> n;
    vector<node> tree(n+1);
    vector<int> cur_vec;
    queue<pair<int, int>> search_tree;
    
    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        if (a == 1) {
            tree[b].prev_node = 1;
            tree[a].next_node.push_back(b);
            search_tree.push(make_pair(1, b));
        }
        else if (b == 1) {
            tree[a].prev_node = 1;
            tree[b].next_node.push_back(a);
            search_tree.push(make_pair(1, a));
        }
        else {
            tree[a].next_node.push_back(b);
            tree[b].next_node.push_back(a); 
        }
    }

    while (!search_tree.empty()) {
        prev_num = search_tree.front().first;
        cur_num = search_tree.front().second;
        tree[cur_num].prev_node = prev_num;
        cur_vec = tree[cur_num].next_node;
        for (auto num : cur_vec) {
            if (num != prev_num) {
                search_tree.push(make_pair(cur_num, num));
            }
        }
        search_tree.pop();
    }

    for (int i=2; i<=n; i++) {
        cout << tree[i].prev_node << '\n';
    }

    return 0;
}