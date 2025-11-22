#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m, answer;
    string input, search;
    unordered_set<string> words;

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>input;
        words.insert(input);
    }

    answer = 0;
    for (int i=0; i<m; i++) {
        cin>>search;
        if (words.find(search) != words.end()) {
            answer++;
        }
    }

    cout<<answer;

    return 0;
}