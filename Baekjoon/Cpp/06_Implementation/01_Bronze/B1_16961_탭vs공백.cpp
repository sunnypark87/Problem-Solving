#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, start, end;
    int sum_open, max_customer;
    int no_fight, no_fight_customer;
    int sum, longest;
    char type;
    vector<vector<int>> hotel(2, vector<int>(366, 0));
    
    cin >> n;
    longest = 0;
    for (int i=0; i<n; i++) {
        cin >> type >> start >> end;
        sum = end - start + 1;
        if (sum > longest) longest = sum;
        if (type == 'T') {
            for (int j=start-1; j<end; j++) {
                hotel[0][j]++;
            }
        }
        else {
            for (int j=start-1; j<end; j++) {
                hotel[1][j]++;
            }
        }
    }

    sum_open = 0;
    max_customer = 0;
    no_fight = 0;
    no_fight_customer = 0;
    for (int i=0; i<366; i++) {
        if (hotel[0][i] + hotel[1][i] > 0) sum_open++;
        if (hotel[0][i] + hotel[1][i] > max_customer) max_customer = hotel[0][i] + hotel[1][i];
        if (hotel[0][i] == hotel[1][i] && hotel[0][i]) {
            if (hotel[0][i] + hotel[1][i] > no_fight_customer) no_fight_customer = hotel[0][i] + hotel[1][i];
            no_fight++;
        }
    }

    cout << sum_open << '\n' << max_customer << '\n' << no_fight << '\n';
    cout << no_fight_customer << '\n' << longest << '\n';
 
    return 0;
}