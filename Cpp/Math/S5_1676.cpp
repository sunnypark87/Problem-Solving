#include <iostream>
using namespace std;

int main(void){

    int n;
    int n_fact=1;
    int count=0;

    cin>>n;
    
    for (int i=1; i<=n; i++){
        n_fact *= i;
        while (n_fact % 10 == 0){
            count++;
            n_fact /= 10;
        }
        if (n_fact > 1000000){
            n_fact %= 1000000;
        }
    }
    cout<<count;
    return 0;
}
