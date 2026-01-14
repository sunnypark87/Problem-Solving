#include <iostream>
#include <algorithm>
using namespace std;
int dp_min[2][3];
int dp_max[2][3];

// 입력값 10만개를 전부 저장하면 메모리 초과
// 메모리 최적화 기법 사용 : 슬라이딩 윈도우
// 모듈러 연산을 사용하지 않고 이전 값을 변수에 저장해 그냥 배열로도 사용 가능 -> 이러면 사실 배열이 필요 없을 수도

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int a, b, c;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a >> b >> c;
        dp_min[i%2][0] = min({dp_min[(i-1)%2][0]+a, dp_min[(i-1)%2][1]+a});
        dp_min[i%2][1] = min({dp_min[(i-1)%2][0]+b, dp_min[(i-1)%2][1]+b, dp_min[(i-1)%2][2]+b});
        dp_min[i%2][2] = min({dp_min[(i-1)%2][1]+c, dp_min[(i-1)%2][2]+c});
        dp_max[i%2][0] = max({dp_max[(i-1)%2][0]+a, dp_max[(i-1)%2][1]+a});
        dp_max[i%2][1] = max({dp_max[(i-1)%2][0]+b, dp_max[(i-1)%2][1]+b, dp_max[(i-1)%2][2]+b});
        dp_max[i%2][2] = max({dp_max[(i-1)%2][1]+c, dp_max[(i-1)%2][2]+c});
    }

    cout << max({dp_max[n%2][0], dp_max[n%2][1], dp_max[n%2][2]}) << ' ';
    cout << min({dp_min[n%2][0], dp_min[n%2][1], dp_min[n%2][2]}) << '\n';

    return 0;
}