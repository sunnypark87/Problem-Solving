#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

int main(void) {

    int n, m, count;
    string name;
    unordered_set<string> name_list;
    priority_queue<string, vector<string>, greater<string>> result;

    cin>>n>>m;
    count = 0;
    for (int i=0; i<n; i++) {
        cin>>name;
        name_list.emplace(name);
    }
    for (int i=0; i<m; i++) {
        cin>>name;
        auto iter = name_list.find(name);
        if (iter != name_list.end()) {
            count++;
            result.push(name); 
        }
    }

    cout<<count<<'\n';
    while (!result.empty()) {
        cout<<result.top()<<'\n';
        result.pop();
    }

    return 0;
}