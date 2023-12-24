#include <iostream>
#include <cmath>
#include <map>
#include <iterator>
#include <queue>

using namespace std;

int main(void) {

    int n, num;
    float avg;
    int medium, count;
    int freq, max_count;
    int max, min;
    priority_queue<int, vector<int>, greater<int>> freqs;
    map<int, int> number_map;
    map<int, int>::iterator iter;

    cin>>n;
    avg = 0;
    max = -4001;
    min = 4001;
    for (int i=0; i<n; i++) {
        cin>>num;
        avg += num;
        if (num > max) max = num;
        if (num < min) min = num;
        if (number_map.find(num) == number_map.end()) {
            number_map.emplace(make_pair(num, 1));
        }
        else {
            number_map[num] += 1;
        }
    }


    count = 1;
    max_count = 0;
    for (iter = number_map.begin(); iter != number_map.end(); iter++) {
        if (count <= (n+1)/2 && count+iter->second > (n+1)/2) {
            medium = iter->first;
        }
        if (iter->second > max_count) {
            max_count = iter->second;
        }
        count += iter->second;
    }

    for (iter = number_map.begin(); iter != number_map.end(); iter++) {
        if (iter->second == max_count) {
            freqs.push(iter->first);
        }
    }

    cout<<avg<<'\n';
    cout<<round(avg/n)<<'\n';

    cout<<medium<<'\n';

    freqs.pop();
    cout<<freqs.top()<<'\n';

    cout<<max - min<<'\n';

}