#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int input, sum;
    int arr[5] = { };

    sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> input;
        sum += input;
        arr[i] = input;
        for (int j = 4; j > 0; j--) {
            if (arr[j] > arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    
    cout << sum/5 << "\n" << arr[2];

    return 0;
}