#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main(void){

    int test_case;
    stack<char> parenthesis;
    vector<string> result;
    string input;

    cin>>test_case;
    for (int i=0; i<test_case; i++){
        cin>>input;
        for (int j=0; j<input.length(); j++){
            if (input[j] == '('){
                parenthesis.push('(');
            }
            else {
                if (parenthesis.empty()){
                    result.push_back("NO");
                    break;
                }
                parenthesis.pop();
            }
        }
        if (result.size() == i || result.empty()){
            if (!parenthesis.empty()){ 
                result.push_back("NO");
            }
            else {
                result.push_back("YES");
            }
        }
        while (!parenthesis.empty()){
            parenthesis.pop();
        }
    }

    for (int i=0; i<test_case; i++){
        cout<<result[i]<<'\n';
    }

    return 0;
}

