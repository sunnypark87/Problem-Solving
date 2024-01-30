#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(void) {

    int depth, prev, answer;
    string input;
    stack<char> parenthesis;
    vector<pair<int, int>> score;
    stack<pair<int, int>> sum;

    cin>>input;
    depth = 1;
    answer = 1;
    // ( : 40, ) : 41, [ : 91, ] : 93
    for (char one : input) {
        if (one == 40) {
            parenthesis.push('(');
            score.push_back(make_pair(2, depth));
            depth++;
        }
        else if (one == 41) {
            if (!parenthesis.empty()) {
                if (parenthesis.top() == 91) {
                    answer = 0;
                    break;
                }
                else {
                    parenthesis.pop();
                    depth--;
                }
            }
            else {
                answer = 0;
                break;
            }
        }
        else if (one == 91) {
            parenthesis.push('[');
            score.push_back(make_pair(3, depth));
            depth++;
        }
        else {
            if (!parenthesis.empty()) {
                if (parenthesis.top() == 40) {
                    answer = 0;
                    break;
                }
                else {
                    parenthesis.pop();
                    depth--;
                }
            }
            else {
                answer = 0;
                break;
            }
        }
    }
    /*
    for (auto iter : score) {
        cout<<iter.first<<" "<<iter.second<<'\n';
    }
    */
    if (parenthesis.empty() && answer != 0) {
        for (int i=0; i<score.size(); i++) {
            if (sum.empty()) {
                //cout<<"push 1 : "<<score[i].first<<" "<<score[i].second<<'\n';
                sum.push(score[i]);
            }
            else if (score[i].second >= sum.top().second) {
                //cout<<"push 2 : "<<score[i].first<<" "<<score[i].second<<'\n';
                sum.push(score[i]);
            }
            else if (score[i].second < sum.top().second) {
                while (score[i].second < sum.top().second) {
                    pair<int, int> temp = sum.top();
                    sum.pop();
                    if (temp.second == sum.top().second) {
                        temp.first += sum.top().first;
                        sum.pop();
                        sum.push(temp);
                        //cout<<"push : "<<temp.first<<" "<<temp.second<<'\n';
                    }
                    else {
                        temp.first *= sum.top().first;
                        temp.second = sum.top().second;
                        sum.pop();
                        sum.push(temp);
                        //cout<<"push : "<<temp.first<<" "<<temp.second<<'\n';
                    }
                }
                //cout<<"push 3 : "<<score[i].first<<" "<<score[i].second<<'\n';
                sum.push(score[i]);
            }
        }
        while (!sum.empty()) {
            pair<int, int> temp = sum.top();
            sum.pop();
            if (sum.empty()) {
                answer = temp.first;
                break;
            }
            if (temp.second == sum.top().second) {
                temp.first += sum.top().first;
                sum.pop();
                sum.push(temp);
            }
            else {
                temp.first *= sum.top().first;
                temp.second = sum.top().second;
                sum.pop();
                sum.push(temp);
            }
        }
    }
    else {
        answer = 0;
    }

    cout<<answer;

    return 0;
}