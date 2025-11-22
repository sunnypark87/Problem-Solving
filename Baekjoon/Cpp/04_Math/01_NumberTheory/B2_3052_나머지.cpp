#include <iostream>
#include <set>
using namespace std;

int main(void){

    int input_num;
    set<int> mod_list;
    int n=42;

    for (int i=0; i<10; i++){
        cin>>input_num;
        mod_list.insert(input_num % n);
    }

    cout<<mod_list.size();
    
    return 0;
}