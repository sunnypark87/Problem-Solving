#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m;
    string name, input;
    int no;
    unordered_map<string, int> names;
    unordered_map<int, string> numbers;

    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>name;
        names[name] = i;
        numbers[i] = name; 
    }

    for (int i=0; i<m; i++) {
        cin>>input;
        try {
            no = stoi(input);
            cout<<numbers[no]<<'\n';
        }
        catch (const invalid_argument& e) {
            cout<<names[input]<<'\n';
        }
    }

    return 0;
}