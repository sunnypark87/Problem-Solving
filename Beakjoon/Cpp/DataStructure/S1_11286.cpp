#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

class abs_compare {
public:
    bool operator()(long long a, long long b) {
        if (abs(a) > abs(b)) {
            return true; 
        }
        else if (abs(a) == abs(b)) {
            if (a > b) return true;
            else return false;
        }
        else {
            return false;
        }
    }

};

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    long long input;
    priority_queue<long long, vector<long long>, abs_compare> numbers;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>input;
        if (input == 0) {
            if (numbers.empty()) {
                cout<<"0"<<'\n';
            }
            else {
                cout<<numbers.top()<<'\n';
                numbers.pop();
            }
        }
        else {
            numbers.push(input);
        }
    }


    return 0;
}