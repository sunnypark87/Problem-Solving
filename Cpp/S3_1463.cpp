#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    
    int x;
    int count;
    int count1, count2, count3;
    vector<int> shortest;

    cin>>x;
    count = 0;

    shortest.push_back(0);
    shortest.push_back(0);
    shortest.push_back(1);
    shortest.push_back(1);

    for (int i=4; i<=x; i++) {
        count2 = 1000000;
        count3 = 1000000;
        if (i % 3 == 0) {
            count3 = shortest[i/3];
        }
        if (i % 2 == 0) {
            count2 = shortest[i/2];
        }
        count1 = shortest[i-1];
        if (count1 < count2) {
            if (count1 < count3) {
                shortest.push_back(count1 + 1);
            }
            else {
                shortest.push_back(count3 + 1);
            }
        }
        else {
            if (count2 < count3) {
                shortest.push_back(count2 + 1);
            }
            else {
                shortest.push_back(count3 + 1);
            }
        }
    }

    cout<<shortest[x];
    
    return 0;
}