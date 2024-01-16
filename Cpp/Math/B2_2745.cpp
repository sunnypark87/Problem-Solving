#include <iostream>
#include <string>
using namespace std;

int main (void) {

    string n;
    int b, count, answer;
    cin>>n>>b;

    count = 1;
    answer = 0;
    for (int i=n.size()-1; i>=0; i--) {
        if (n[i]>=48 && n[i]<=57) {
            answer += count*(n[i]-48);
        }
        else {
            answer += count*(n[i]-55);
        }
        count *= b;
    }

    cout<<answer;

    return 0; 
}