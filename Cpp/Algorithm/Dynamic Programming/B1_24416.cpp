#include <iostream>
#include <vector>
using namespace std;

int recursive_fib(int n, long long int& count) {
    if (n == 1 || n == 2) return 1;
    else {
        count++;
        return recursive_fib(n-1, count) + recursive_fib(n-2, count);
    }
}

int main(void) {

    int n;
    int fib;
    long long int answer1, answer2;

    cin>>n;

    answer1 = 0;
    fib = recursive_fib(n, answer1);

    answer2 = 0;
    vector<int> dp_fib(n);
    dp_fib[0] = 1;
    dp_fib[1] = 1;
    for (int i=2; i<n; i++) {
        answer2++;
        dp_fib[i] = dp_fib[i-1] + dp_fib[i-2];
    }

    cout<<answer1+1<<" "<<answer2;

    return 0;
}