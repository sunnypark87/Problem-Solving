#include <iostream>
#include <climits>
using namespace std;

// 그리디로 풀기
// B에서 A로 역연산을 하면 굳이 분기할 필요가 없다. 
// 최소 횟수 문제에서 역연산이 확정적일 때는 그리디를 사용한다.

/* 원래 코드 
void operation(long long &a, long long &b, int &count, int &answer) {
    if (a == b) {
        if (count < answer) answer = count;
        return;
    }
    if (a > b) {
        return;
    }
    a *= 2;
    count++;
    operation(a, b, count, answer);
    a /= 2;
    a = a*10 + 1;
    operation(a, b, count, answer);
    a /= 10;
    count--;
}

int main(void) {

    long long a, b;
    int count=0, answer=INT_MAX;
    cin >> a >> b;

    operation(a, b, count, answer);

    if (answer == INT_MAX) {
        cout << -1 << '\n';
    }
    else {
        cout << answer+1 << '\n';
    }


    return 0;
}
*/

int main(void) {
    long long a, b;
    int count=0;
    cin >> a >> b;

    while (1) {
        if (b == a) {
            count++;
            break;
        }
        else if (b < a) {
            count = -1;
            break;
        }
        cout << "a : " << a << " b : " << b << '\n';
        if (b%2 == 0) {
            b /= 2;
        }
        else if (b%10 == 1) {
            b /= 10;
        } else {
            count = -1;
            break;
        }
        count++;
    }

    cout << count << '\n';

    return 0;
}