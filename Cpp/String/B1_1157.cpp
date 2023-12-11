#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {

    string word;
    char max_char;
    int max_int;
    int multi_answer;
    map<char, int> alphabet;

    cin>>word;
    transform(word.begin(), word.end(), word.begin(), ::toupper);
    for (int i=0; i<word.length(); i++) {
        if (alphabet.find(word[i]) != alphabet.end()) {
            alphabet[word[i]]++;
        }
        else {
            alphabet.insert({word[i], 1});
        }
    }

    max_int=0;

    for (auto iter=alphabet.begin(); iter!=alphabet.end(); iter++) {
        if (iter->second > max_int) {
            max_char = iter->first;
            max_int = iter->second;
        }
    }

    multi_answer = 0;
    for (auto iter=alphabet.begin(); iter!=alphabet.end(); iter++) {
        if (max_int == iter->second && max_char != iter->first) {
            multi_answer=1;
        }
    }

    if (multi_answer == 1) cout<<"?";
    else cout<<max_char;

    return 0;
}