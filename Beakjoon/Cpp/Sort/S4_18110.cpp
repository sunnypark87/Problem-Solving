#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double n;
    double cutoff;
    double input;
    double sum=0;
    double result;
    priority_queue<double> difficulty;

    cin>>n;
    if (n == 0){
        result = 0;
        cout<<result<<'\n';
        return 0;
    }
    for (int i=0; i<n; i++){
        cin>>input;
        difficulty.push(input);
    }

    cutoff = round(n*15/100);

    while(!difficulty.empty()){
        if ((difficulty.size() <= n-cutoff) && (difficulty.size() >= 1+cutoff)){
            sum += difficulty.top();
        }
        difficulty.pop();
    }

    result = round(sum / (n - 2*cutoff));
    cout<<result;

    return 0;
}