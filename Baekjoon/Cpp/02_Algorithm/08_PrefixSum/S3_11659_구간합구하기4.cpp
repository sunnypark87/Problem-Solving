#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int n, m;
    int input;
    int first, end;
    int sum;

    cin>>n>>m;
    vector<int> numbers(n, 0);
    vector<int> sum_of_numbers(n+1, 0);

    sum_of_numbers.push_back(0);
    for (int i=0; i<n; i++) {
        cin>>input;
        numbers[i] = input;
        sum_of_numbers[i+1] = sum_of_numbers[i] + numbers[i];
    }

    for (int i=0; i<m; i++) {
        cin>>first>>end;
        sum = sum_of_numbers[end] - sum_of_numbers[first-1];
        cout<<sum<<'\n';
    }

    return 0;
}