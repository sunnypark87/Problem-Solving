#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int input;
    priority_queue<int, vector<int>, greater<int>> num_list;

    cin>>n;

    for (int i=0; i<n; i++){
        cin>>input;
        num_list.push(input);
    }

    for (int i=0; i<n; i++){
        cout<<num_list.top()<<"\n";
        num_list.pop();
    }

    return 0;
}