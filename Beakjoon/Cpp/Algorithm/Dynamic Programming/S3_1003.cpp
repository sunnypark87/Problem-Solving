#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int fibonacci(int n, int& zero, int& one) {
    if (n == 0) {
        zero++;
        return 0;
    }
    else if (n == 1) {
        one++;
        return 1;
    }
    else {
        return fibonacci(n-1, zero, one) + fibonacci(n-2, zero, one);
    }
}

int main(void) {

    int test_case;
    int n, zero_count, one_count;
    vector<pair<int, int>> fibonacci_list;
    int f_result;

    fibonacci_list.push_back(make_pair(1, 0));
    fibonacci_list.push_back(make_pair(0, 1));
    fibonacci_list.push_back(make_pair(1, 1));

    cin>>test_case;
    for (int i=0; i<test_case; i++) {
        cin>>n;
        if (fibonacci_list.size() <= n) {
            for (int j=fibonacci_list.size(); j<=n; j++) {
                fibonacci_list.push_back(make_pair(fibonacci_list[j-1].second, fibonacci_list[j-1].second + fibonacci_list[j-1].first));
            }
        }
        cout<<fibonacci_list[n].first<<" "<<fibonacci_list[n].second<<'\n';
    }

    return 0;
}