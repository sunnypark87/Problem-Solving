#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(void) {

    string word;
    string part;
    unordered_set<string> string_set;

    cin>>word;
    for (int i=0; i<word.size(); i++) {
        for (int j=0; j<word.size()-i; j++) {
            part = "";
            for (int k=0; k<i+1; k++) {
                part += word[j+k];
            }
            //cout<<part<<"\n";
            string_set.insert(part);
        }
    }

    cout<<string_set.size();

    return 0;
}