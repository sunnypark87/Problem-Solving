#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {

    int n, count, answer;
    string input;

    cin>>n;
    answer = 0;
    for (int i=0; i<n; i++) {
        cin>>input;
        count = 0;
        vector<int> alphabet(26, 0);
        for (int j=0; j<input.size(); j++) {
            if (alphabet[input[j]-97] != 0) {
                if (j > 0) {
                    if (input[j-1] != input[j]) {
                        break;
                    }
                }   
            }
            alphabet[input[j]-97]++;
            count++;
        }
        if (count == input.size()) {
            answer++;
        }
    }

    cout<<answer;

    return 0;
}