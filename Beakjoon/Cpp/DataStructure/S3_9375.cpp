#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {

    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int test_case, number, answer, mul;
    string name, type;
    unordered_map<string, int> clothes;

    cin>>test_case;
    for (int i=0; i<test_case; i++) {
        cin>>number;
        for (int j=0; j<number; j++) {
            cin>>name>>type;
            auto iter = clothes.find(type);
            if (iter != clothes.end()) {
                clothes[type]++;
            }
            else {
                clothes[type] = 1;
            }
        }
        answer = 1;
        for (const auto pair : clothes) {
            answer *= pair.second+1;
        }
        answer -= 1;
        cout<<answer<<'\n';

        clothes.clear();
    }

    return 0;
}