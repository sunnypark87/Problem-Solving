#include <iostream>
using namespace std;

int calculate_gcd(int n1, int n2){
    int mod;
    while(n1 % n2){
        mod = n1 % n2;
        n1 = n2;
        n2 = mod;
    }
    return n2;
}

int main(void){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n1, n2;
    int gcd, lcm;

    cin>>n1>>n2;

    gcd = calculate_gcd(n1, n2);
    
    lcm = n1/gcd * n2/gcd * gcd;

    cout<<gcd<<"\n"<<lcm<<"\n";

    return 0;
}