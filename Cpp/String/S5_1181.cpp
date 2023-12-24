#include <iostream>
#include <string>
#include <set>

using namespace std;

struct Compare_string {
    bool operator()(string a, string b) const {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        }
        else {
            for (int i=0; i<a.length(); i++) {
                if (a[i] != b[i]) {
                    return a < b;
                }
            }
        }
    }
};

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    string input;
    set<string, Compare_string> words;

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>input;
        words.emplace(input);
    }

    for (string element : words) {
        cout<<element<<"\n";
    }

    return 0;
}