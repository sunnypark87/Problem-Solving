#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main(void) {

    int k, n;
    long long line, sum_line, max;
    long long min_line, max_line, mid_line;
    vector<long long> lines;

    cin>>k>>n;
    max = 0;
    for (int i=0; i<k; i++) {
        cin>>line;
        if (max < line) max = line;
        lines.push_back(line);
    }

    min_line = 0;
    max_line = max;
    while (min_line <= max_line) {
        mid_line = (min_line + max_line) / 2;
        if (mid_line == 0) break;
        sum_line = 0;
        for (int i=0; i<k; i++) {
            sum_line += lines[i] / mid_line;
        }
        if (sum_line >= n) {
            min_line = mid_line + 1;
        }
        else {
            max_line = mid_line - 1;
        }
    }

    cout<<max_line<<"\n";

    cout<<"min : "<<min_line<<"\n";
    cout<<"max : "<<max_line<<"\n";
    cout<<"mid : "<<mid_line<<"\n";

    return 0;
}
