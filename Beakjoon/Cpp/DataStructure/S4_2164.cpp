#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n;
    queue<int> card;
    int answer;

    cin>>n;
    for (int i=1; i<=n; i++) {
        card.push(i);
    }

    if (n == 1) {
        answer = 1;
        cout<<answer<<'\n';
        return 0;
    }

    while (!card.empty()) {
        card.pop();
        answer = card.front();
        card.pop();
        if (card.empty()) break;
        card.push(answer);
    }

    cout<<answer<<'\n';

    return 0;
}