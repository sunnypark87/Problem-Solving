#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    int n, goal, coin;

    cin>>n>>goal;
    vector<int> coins(n);
    vector<int> answer(goal+1, 0); 
    for (int i=0; i<n; i++) {
        cin>>coins[i];
    }

    answer[0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=goal; j++) {
            if (j >= coins[i]) {
                answer[j] += answer[j-coins[i]];
            }
        }
    }

    cout<<answer[goal];

    return 0;
}