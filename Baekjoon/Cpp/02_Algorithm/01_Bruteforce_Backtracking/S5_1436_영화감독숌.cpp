#include <iostream>
#include <regex>

using namespace std;

int main(void) {

    int n;
    int answer, count;
    string answer_str;
    regex pattern("\\d*(666)\\d*");

    
    cin>>n;
    
    count = 0;
    answer = 666;
    while (true) {
        answer_str = to_string(answer);
        if (regex_match(answer_str, pattern)) {
            count++;
        }
        if (count == n) {
            break;
        }
        answer++;
    }
    cout<<answer;
    

    return 0;
}