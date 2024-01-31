#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

int main(void) {

    int a, b;
    int input, answer;
    unordered_set<int> set_a;
    unordered_set<int> set_b;
    set<int> set_ab;

    cin>>a>>b;
    for (int i=0; i<a; i++) {
        cin>>input;
        set_a.insert(input);
    }
    for (int i=0; i<b; i++) {
        cin>>input;
        set_b.insert(input);
        if (set_a.find(input) != set_a.end()) {
            set_ab.insert(input);
        }
    }

    answer = set_a.size() + set_b.size() - 2*set_ab.size();

    cout<<answer;

    return 0;
}