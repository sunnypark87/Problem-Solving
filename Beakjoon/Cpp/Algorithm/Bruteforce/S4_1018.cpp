#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m;
    int wrong, result;
    string line;
    string filter1 = "WBWBWBWB";
    string filter2 = "BWBWBWBW";
    vector<string> board;

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>line;
        board.push_back(line);
    }

    result = 100;
    for (int i=0; i<n-7; i++) {
        for (int j=0; j<m-7; j++) {
            for (int wb=0; wb<=1; wb++) {
                wrong = 0;
                for (int k=0; k<8; k++) {
                    for (int l=0; l<8; l++) {
                        if (wb == 0) {
                            if (k%2 == 0) {
                                if (board[k+i][l+j] != filter1[l]) {
                                    wrong++;
                                } 
                            }
                            else {
                                if (board[k+i][l+j] != filter2[l]) {
                                    wrong++;
                                }
                            }
                        }
                        else {
                            if (k%2 == 0) {
                                if (board[k+i][l+j] != filter2[l]) {
                                    wrong++;
                                }
                            }
                            else {
                                if (board[k+i][l+j] != filter1[l]) {
                                    wrong++;
                                }
                            }
                        }
                    }
                }
                if (result > wrong) {
                    //cout<<"n : "<<i<<" m : "<<j<<" WB : "<<wb<<'\n';
                    result = wrong;
                }
            }
        }
    }

    cout<<result;

    return 0;
}