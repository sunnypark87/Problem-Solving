#include <iostream>
#include <queue>
using namespace std;

int main(void) {

    int n, input;
    priority_queue<int> max_heap;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>input;
        if (input == 0) {
            if (max_heap.empty()) {
                cout<<"0\n";
            }
            else {
                cout<<max_heap.top()<<"\n";
                max_heap.pop();
            }
        }
        else {
            max_heap.push(input);
        }
    }
    return 0;
}