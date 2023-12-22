#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m;
    string address, password;
    unordered_map<string, string> passwords;

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>address>>password;
        passwords.emplace(address, password);
    }

    for (int i=0; i<m; i++) {
        cin>>address;
        auto search = passwords.find(address);
        cout<<search->second<<'\n';
    }

    return 0;
}