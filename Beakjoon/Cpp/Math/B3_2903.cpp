#include <iostream>
using namespace std;

int main(void) {

    int n, point;
    int answer;
    cin>>n;

    point = 2;
    for (int i=0; i<n; i++) {
        point += (point-1);
    }

    answer = point * point;
    cout<<answer;

    return 0;
}