#include <iostream>
#include <string>

using namespace std;

int main(void) {


    int n;
    string testcase;
    int score;
    int continuous;

    cin>>n;
    for (int i=0; i<n; i++) {
        score = 0;
        cin>>testcase;
        continuous = 0;
        for (int j=0; j<testcase.length(); j++) {
            if (testcase[j] == 'O') {
                score += continuous + 1;
                continuous++;
            }
            else {
                continuous = 0;
            }
        }
        cout<<score<<'\n';
    }

    return 0;
}