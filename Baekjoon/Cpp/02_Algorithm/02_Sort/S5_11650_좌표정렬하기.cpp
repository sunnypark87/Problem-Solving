#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

class Compare{
public:
    bool operator()(tuple<int, int> t1, tuple<int, int> t2){
        if (get<0>(t1) > get<0>(t2)){
            return true;
        }
        else if (get<0>(t1) == get<0>(t2)){
            if (get<1>(t1) > get<1>(t2)){
                return true;
            }
        }
        return false;
    }
};

int main(void){

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N;
    int x, y;
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, Compare> coordinate;
    tuple<int, int> point;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>x>>y;
        coordinate.push(make_tuple(x, y));
    }

    for (int i=0; i<N; i++){
        point = coordinate.top();
        cout<<get<0>(point)<<" "<<get<1>(point)<<'\n';
        coordinate.pop();
    }

    return 0;
}