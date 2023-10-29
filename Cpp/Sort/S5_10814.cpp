#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

class Heap{
private:
    int n;
    vector<tuple<int, string>> member_vector;
public:
    Heap(){
        n = 1;
        member_vector.emplace_back(0, "");
    }
    void add(int age, string name);
    void print();
};

void Heap::add(int age, string name){
    int index;
    while(1){
        
    }
}

void Heap::print(){
    int age, name;
    for (int i=1; i<=n; i++){
        cout<<get<0>(member_vector.at(i))<<" "<<get<1>(member_vector.at(i))<<"\n";
    }
}


int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int age;
    string name;
    Heap member_list;

    cin>>n;
    for (int i=0; i<n; i++){
        cin>>age>>name;
        member_list.add(age, name);
    }

    member_list.print();

    return 0;
}