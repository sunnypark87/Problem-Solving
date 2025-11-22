#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string command;
    int n, x;
    int one_to_twenty[20] = {};

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>command;
        if (command == "add") {
            cin>>x;
            one_to_twenty[x-1] = 1;
        }
        else if (command == "remove") {
            cin>>x;
            one_to_twenty[x-1] = 0;
        }
        else if (command == "check") {
            cin>>x;
            cout<<one_to_twenty[x-1]<<'\n';
        }
        else if (command == "toggle") {
            cin>>x;
            if (one_to_twenty[x-1]) 
                one_to_twenty[x-1] = 0;
            else 
                one_to_twenty[x-1] = 1;
        }
        else if (command == "all") {
            for (int j=0; j<20; j++) {
                one_to_twenty[j] = 1;
            }
        }
        else if (command == "empty") {
            for (int j=0; j<20; j++) {
                one_to_twenty[j] = 0;
            }
        }
    }


    return 0;
}