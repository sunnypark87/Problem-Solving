#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Compare {
public:
    bool operator()(tuple<int, int, string> t1, tuple<int, int, string> t2){
        if (get<0>(t1) > get<0>(t2)){
            return true;
        }
        else if (get<0>(t1) == get<0>(t2)){
            if (get<1>(t1) > get<1>(t2)){
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
};

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int age;
    int count;
    string name;
    priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, Compare> members;

    cin>>n;
    count = 0;
    for (int i=0; i<n; i++){
        cin>>age>>name;
        members.push(make_tuple(age, count, name));
        count++;
    }

    while(!members.empty()){
        tuple<int, int, string> member = members.top();
        cout<<get<0>(member)<<' '<<get<2>(member)<<'\n';
        members.pop();
    }

    return 0;
}